#pragma once
#include <string>

class Expense
{
    float amount;
    std::string currency = "CAD"; // default is CAD
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

    void convertCurrency(float newCurrency) {
        currency = newCurrency;
        // TODO: Convert amount
    }
};