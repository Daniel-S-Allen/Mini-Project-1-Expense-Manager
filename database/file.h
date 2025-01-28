#pragma once
#include "../Expense/Expense.h"
#include "category.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
class DatabaseIO {
	static constexpr char PADDING = '\t';
	public:
	static std::string padding(char c, int count) {
		std::string		  output;
		std::stringstream out(output);
		for (int i = 0; i < count; i++) {
			out << c;
		}
		return out.str();
	}
	static std::string trim_left(std::string input){
		return input.substr(input.find_first_not_of(PADDING));
	}
	static void writeToFile(const std::string &filename, const Category &root) {
		std::ofstream out(filename);
		if(out.is_open()){
			out << serializeCategory(root);
		} else {
			throw std::runtime_error("Failed to write to file!");
		}
	}
	static std::string serializeCategory(const Category &category, int depth = 0) {
		std::string		  output;
		std::stringstream out(output);
		out << padding(PADDING, depth) << category.getName() << "\n";
		out << padding(PADDING, depth) << category.expenses.size() << "\n";
		for (const Expense& e : category.expenses) {
			out << serializeExpense(e, depth + 1);
		}
		out << padding(PADDING, depth) << category.subcategories.size() << "\n";
		for (const Category& c : category.subcategories) {
			out << serializeCategory(c, depth + 1);
		}
		return out.str();
	}
	static std::string serializeExpense(const Expense &e, int depth = 0) {
		std::string		  output;
		std::stringstream out(output);
		out << padding(PADDING, depth) << e.getID() << "\n";
		out << padding(PADDING, depth+1) << e.getAmount() << "\n";
		out << padding(PADDING, depth+1) << e.getCurrency() << "\n";
		out << padding(PADDING, depth+1) << e.getDate() << "\n";
		return out.str();
	};
	static Category readFromFile(const std::string& filename){
		std::ifstream in(filename);
		if(in.is_open()){
			Category out = deserializeCategory(in);
			return out;
		}
		throw std::runtime_error("Failed to read from file!");
	}
	static Category deserializeCategory(std::ifstream& in){
		std::string line;
		
		std::getline(in, line);
		Category cat(trim_left(line));
		
		std::getline(in, line);
		int entrySize = stoi(trim_left(line));
		for(int i = 0; i < entrySize; i++){
			Expense e = deserializeExpense(in);
			cat.addEntry(e);
		}
		
		std::getline(in, line);
		int categorySize = stoi(trim_left(line));
		while(categorySize > 0){
			Category add = deserializeCategory(in);
			cat.addCategory(add);
			categorySize--;
		}
		return cat;
	}
	static Expense deserializeExpense(std::ifstream& in){
		std::string line;
		
		std::getline(in, line);
		int id = stoi(trim_left(line));
		
		std::getline(in, line);
		double amount = stod(trim_left(line));
		
		std::getline(in, line);
		std::string locale = trim_left(line);
		
		std::getline(in, line);
		std::string date = trim_left(line);
		
		return Expense(amount,locale,date);
	}
};