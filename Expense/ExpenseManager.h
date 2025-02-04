#include "Expense.h"
#include <vector>
#include <string>

class ExpenseManager
{
public:
    std::vector<Expense> expenseList;
    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="") {}
    void removeExpense() {}
};