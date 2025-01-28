#pragma once
#include "../Expense/Expense.h"
#include <string>
#include <vector>
class Category{
	public:
	std::string name;
	std::vector<Category> subcategories;
	std::vector<Expense> expenses;
	Category(std::string name) : name(name){
		
	}
	public:
	std::string getName(){
		return name;
	}
	void addCategory(Category& category){
		subcategories.push_back(category);
	}
	void addEntry(Expense& expense){
		expenses.push_back(expense);
	}
};