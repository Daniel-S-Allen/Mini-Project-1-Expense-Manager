#pragma once
#include "../Expense/Expense.h"
#include "../utilities.h"
#include <string>
#include <vector>

class Category {
public:
	std::string			  name;
	std::vector<Category> subcategories;
	std::vector<Expense>  expenses;

	Category(std::string name) : name(Utilities::escape(std::move(name))) {
	}

	std::string getName() const {
		return name;
	}

	void addCategory(const Category &category) {
		subcategories.push_back(category);
	}

	void addEntry(const Expense &expense) {
		expenses.push_back(expense);
	}

	bool operator==(const Category &other) const {

		// test vector lengths before checking the vectors themselves for performance reasons
		if (this->expenses.size() != other.expenses.size()) {
			return false;
		}
		if (this->subcategories.size() != other.subcategories.size()) {
			return false;
		}
		if (this->name != other.name) {
			return false;
		}
		// test vector contents
		for (size_t i = 0; i < this->expenses.size(); i++) {
			if (this->expenses[i] != other.expenses[i]) {
				return false;
			}
		}
		for (size_t i = 0; i < this->subcategories.size(); i++) {
			if (this->subcategories[i] != other.subcategories[i]) {

				return false;
			}
		}
		return true;
	}
};