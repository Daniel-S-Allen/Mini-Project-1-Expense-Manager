#include "Expense.h"
#include <vector>
#include <string>
#include "database/file.h"
#include "database/category.h"

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;
    std::vector <Category> categoryList;
public:
    ExpenseManager() {}
    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="", std::string category="") {}
    void removeExpense() {}
};