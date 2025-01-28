#include <string>

class Expense
{
    float amount;
    std::string description;
    // TODO: add time and date as well
public:
    Expense(float amt, std::string desc): amount(amt), description(desc) {};
    
    float getAmount()
    {
        return amount;
    }

    void setAmount(float newAmount)
    {
        amount = newAmount;
    }
};