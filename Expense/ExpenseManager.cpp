#include "Expense.h"
#include <vector>
#include <string>
#include <regex>

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;

    bool isDateValid(std::string &date) {
        std::regex dateRegex(R"(^\d{4}-\d{1,2}-\d{1,2}$)");
        return std::regex_match(date, dateRegex);
    }
public:
    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="")
    {
        // TODO: Check if date is invalid — format: "yyyy-mm-dd".
        if (isDateValid(date)) {
            this->expenseList.push_back(Expense(amt, curr, desc, date));
        }
        else {
            this->expenseList.push_back(Expense(amt, curr, desc));
        }
    }

    void removeLastExpense()
    {
        this->expenseList.pop_back();
    }
};