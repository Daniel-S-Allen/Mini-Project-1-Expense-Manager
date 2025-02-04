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
        std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)"); // will ensure that date is in one of the following formats: "yyyy-mm-dd", "yyyy-m-dd", "yyyy-mm-d", "yyyy-m-d". Any other format is considered invalid & default date will be used.
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

    void addExpense(float amt, std::string curr = "CAD", std::string desc="", std::string date="", std::string cat="")
    {
        Category category = this->root;

        try
        {
            for (auto &subcat : this->root.subcategories) {
                if (subcat.getName() == cat) {
                    category = subcat;
                    break;
                }
            }
        }
        catch (std::runtime_error &e)
        {
            category = Category(cat);
            this->root.addCategory(category);
        }

        // Checks if date is invalid.
        if (isDateValid(date)) {
            Expense expense(amt, curr, desc, date);
            category.addEntry(expense);
        } else {
            Expense expense(amt, curr, desc);
            category.addEntry(expense);
        }

        // Write everything to the file.
        DatabaseIO::writeToFile("database/expenses.txt", this->root);
    }

    void removeLastExpense()
    {
        // TODO
    }
};