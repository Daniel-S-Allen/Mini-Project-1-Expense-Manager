#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <string>
#include "Expense/Expense.h"


std::vector<Expense> filterByKeyword(const std::vector<Expense>& expenses, const std::string& keyword);


void sortByID(std::vector<Expense>& expenses);
void sortByTime(std::vector<Expense>& expenses);
void sortByAmount(std::vector<Expense>& expenses);


void displayMenu();
void displayExpenses(std::vector<Expense>& expenses);

void sortDisplay();

#endif 