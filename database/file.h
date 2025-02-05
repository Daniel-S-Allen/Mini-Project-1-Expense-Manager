#pragma once
#include "../Expense/Expense.h"
#include "../utilities.h"
#include "category.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace DatabaseIO {
	static bool fileExists(const std::string &filepath) {
		return std::filesystem::exists(filepath);
	}

	/**
	 * @brief Generates a string serialization of an expense
	 *
	 * @param e An expense to serialize
	 * @param depth The depth of the category (how many parents it has)
	 * @return std::string Serialized expense
	 */
	static std::string serializeExpense(const Expense &e, int depth = 0) {
		std::string		  output;
		std::stringstream out(output);
		out << Utilities::padding(depth) << e.getID() << "\n";
		out << Utilities::padding(depth + 1) << e.getAmount() << "\n";
		out << Utilities::padding(depth + 1) << Utilities::escape(e.getCurrency()) << "\n";
		out << Utilities::padding(depth + 1) << Utilities::escape(e.getDate()) << "\n";
		out << Utilities::padding(depth + 1) << Utilities::escape(e.getDescription()) << "\n";
		return out.str();
	};

	/**
	 * @brief Generates a string serialization of a category
	 *
	 * @param category A category to serialize
	 * @param depth The depth of the category (how many parents it has)
	 * @return std::string Serialized category
	 */
	static std::string serializeCategory(const Category &category, int depth = 0) {
		std::string		  output;
		std::stringstream out(output);
		out << Utilities::padding(depth) << Utilities::escape(category.getName()) << "\n";
		out << Utilities::padding(depth) << category.expenses.size() << "\n";
		for (const Expense &e : category.expenses) {
			out << serializeExpense(e, depth + 1);
		}
		out << Utilities::padding(depth) << category.subcategories.size() << "\n";
		for (const Category &c : category.subcategories) {
			out << serializeCategory(c, depth + 1);
		}
		return out.str();
	}

	/**
	 * @brief Write a category to a file, typically the root node.
	 * If the file cannot be written to, throws a runtime error.
	 * @param filename The filename to write to.
	 * @param root The category to write
	 */
	static void writeToFile(const std::string &filename, const Category &root) {
		std::ofstream out(filename);
		if (out.is_open()) {
			out << serializeCategory(root);
		} else {
			throw std::runtime_error("Failed to write to file!");
		}
	}

	/**
	 * @brief Creates a new file. If the file already exists, throws a runtime error.
	 *
	 * @param filename
	 */
	static void createNewFile(const std::string &filename) {
		if (fileExists(filename)) {
			throw std::runtime_error("File already exists!");
		}
		std::ofstream out(filename);
		out << "Root\n0\n0";
		out.close();
	}

	/**
	 * @brief Deserialize an expense from an input stream
	 *
	 * @param in
	 * @return Expense
	 */
	static Expense deserializeExpense(std::ifstream &in) {
		std::string line;

		std::getline(in, line);
		int id = stoi(Utilities::trim_left(line));

		std::getline(in, line);
		float amount = stod(Utilities::trim_left(line));

		std::getline(in, line);
		std::string locale = Utilities::unescape(Utilities::trim_left(line));

		std::getline(in, line);
		std::string date = Utilities::unescape(Utilities::trim_left(line));

		std::getline(in, line);
		std::string description = Utilities::unescape(Utilities::trim_left(line));

		return {amount, locale, description, date};
	}

	/**
	 * @brief Deserialize a category from an input stream.
	 *
	 * @param in An input stream
	 * @return Category
	 */
	static Category deserializeCategory(std::ifstream &in) {
		std::string line;

		std::getline(in, line);
		Category cat(Utilities::unescape(Utilities::trim_left((line))));

		std::getline(in, line);
		int entrySize = stoi(Utilities::trim_left(line));
		for (int i = 0; i < entrySize; i++) {
			Expense e = deserializeExpense(in);
			cat.addEntry(e);
		}

		std::getline(in, line);
		int categorySize = stoi(Utilities::trim_left(line));
		while (categorySize > 0) {
			Category add = deserializeCategory(in);
			cat.addCategory(add);
			categorySize--;
		}
		return cat;
	}

	/**
	 * @brief Read a category from a file, typically the root node.
	 * If the file cannot be read, including if it does not exist, throws a runtime error.
	 * @param filename The filename to read.
	 * @return Category
	 */
	static Category readFromFile(const std::string &filename) {
		if (!fileExists(filename)) {
			throw std::runtime_error("File not found!");
		}
		std::ifstream in(filename);
		if (in.is_open()) {
			Category out = deserializeCategory(in);
			return out;
		}
		throw std::runtime_error("Failed to read from file!");
	}
}; // namespace DatabaseIO