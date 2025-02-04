#include "Expense.h"
#include <vector>
#include <string>

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;
public:
    void addExpense(int amt, std::string curr = "CAD", std::string desc="")
    {
        this->expenseList.push_back(Expense(amt, curr, desc));
    }
};