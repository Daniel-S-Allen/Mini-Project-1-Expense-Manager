#include <string>

class Expense
{
    float amount;
    std::string currency = "CAD"; // default is CAD
    std::string description;

    static int numOfExpenses;
    int ID;

    // TODO: add time and date as well

public:
    Expense(float amt, std::string curr, std::string desc): amount(amt), currency(curr), description(desc)
    {
        ID = numOfExpenses;
        numOfExpenses++;
    };

    void convertCurrency(float newCurrency) {
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
};

int Expense::numOfExpenses = 0;