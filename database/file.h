#pragma once
#include "../Expense/Expense.h"
#include "category.h"
#include <fstream>
#include <sstream>
#include <string>

class DatabaseIO {
	/*
	Read a category from file. This is usually the root of the database.
	*/
	Category readFromFile(const std::string &filepath) {
		std::ifstream in(filepath);
		std::string	  line;
		std::string	  lastDepth = 0;
		while (std::getline(in, line)) {
			int depth = 0;
			while (line[depth] == '\t') {
				depth++;
			}
		}
	}

	void writeToFile(const std::string &filepath, const Category &root) {
		std::ofstream out;
	}

	std::string serializeCategory(Category &category, int depth) {
		std::string		  output;
		std::stringstream out(output);
		for (Expense e : category.expenses) {
			
		}
	}

	std::string serializeExpense(Expense &e) {
		std::string		  output;
		std::stringstream out(output);
		//out << std::string(e.getID());
	}
	
};