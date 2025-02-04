#include "Expense.h"
#include <vector>
#include <string>

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;
public:
    void addExpense(int amt, std::string curr = "CAD", std::string desc="", std::string date="")
    {
        // TODO: Check if date is invalid
        if (date == "") {
            this->expenseList.push_back(Expense(amt, curr, desc));
        }
        else {
            this->expenseList.push_back(Expense(amt, curr, desc, date));
        }
    }

    void removeLastExpense()
    {
        this->expenseList.pop_back();
    }
};