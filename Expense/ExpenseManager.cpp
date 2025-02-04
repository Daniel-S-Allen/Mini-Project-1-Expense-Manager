#include "Expense.h"
#include <vector>
#include <string>
#include <regex>
#include "database/file.h"

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;
    std::vector<Category> categoryList;

    bool isDateValid(std::string &date) {
        std::regex dateRegex(R"(^\d{4}-\d{1,2}-\d{1,2}$)"); // will ensure that date is in one of the following formats: "yyyy-mm-dd", "yyyy-m-dd", "yyyy-mm-d", "yyyy-m-d". Any other format is considered invalid & default date will be used.
        return std::regex_match(date, dateRegex);
    }
public:
    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="")
    {
        // Checks if date is invalid.
        if (isDateValid(date)) {
            this->expenseList.push_back(Expense(amt, curr, desc, date));
        }
        else {
            this->expenseList.push_back(Expense(amt, curr, desc));
        }

        for (auto &category : categoryList) {
            DatabaseIO::writeToFile("expenses.txt", category);
        }
    }

    void removeLastExpense()
    {
        this->expenseList.pop_back();
    }
};