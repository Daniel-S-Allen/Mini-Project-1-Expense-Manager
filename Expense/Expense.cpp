#include <string>
#include <ctime>

class Expense
{
    float amount;
    std::string currency = "CAD"; // default is CAD
    std::string description;

    static int numOfExpenses;
    int ID;

    std::string date;

public:
    Expense(float amt, std::string curr, std::string desc): amount(amt), currency(curr), description(desc)
    {
        // Set ID of expense
        ID = numOfExpenses;
        numOfExpenses++;

        // Set date to current date
        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);

        date = std::to_string(now->tm_year + 1900) + '-' + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday);
    };

    void convertCurrency(std::string newCurrency) {
        currency = newCurrency;
        // TODO: Convert amount
    }
    
    float getAmount()
    {
        return this->amount;
    }

    void setAmount(float newAmount)
    {
        amount = newAmount;
    }

    int getID() 
    {
        return this->ID;
    }

    std::string getDate()
    {
        return this->date;
    }
};

int Expense::numOfExpenses = 0;