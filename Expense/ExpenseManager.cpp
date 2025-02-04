#include "Expense.h"
#include <vector>
#include <string>
#include <regex>
#include "database/file.h"
#include "database/category.h"

class ExpenseManager
{
private:
    std::vector<Expense> expenseList;
    Category root;

    bool isDateValid(std::string &date) {
        std::regex dateRegex(R"(^\d{4}-\d{1,2}-\d{1,2}$)"); // will ensure that date is in one of the following formats: "yyyy-mm-dd", "yyyy-m-dd", "yyyy-mm-d", "yyyy-m-d". Any other format is considered invalid & default date will be used.
        return std::regex_match(date, dateRegex);
    }
public:
    ExpenseManager() : root("root")
    {
        // Read file
        try {
            this->root = DatabaseIO::readFromFile("expenses.txt");
        }
        catch (std::runtime_error &e) {
            this->root = Category("root");
        }
    }

    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="", std::string category="")
    {
        // Checks if date is invalid.
        if (isDateValid(date)) {
            this->expenseList.push_back(Expense(amt, curr, desc, date));
        }
        else {
            this->expenseList.push_back(Expense(amt, curr, desc));
        }

        // Write everything to the file.
        DatabaseIO::writeToFile("database/expenses.txt", this->root);
    }

    void removeLastExpense()
    {
        // TODO
    }
};