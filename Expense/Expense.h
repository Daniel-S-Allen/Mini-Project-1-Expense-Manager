#pragma once
#include <string>

class Expense
{
    float amount;
    std::string currency;
    std::string description;

    std::string date;

    static int numOfExpenses;
    int ID;

public:
    Expense(float a, std::string c, std::string d): amount(a), currency(c), description(d) {}

    void convertCurrency(float newCurrency);

    float getAmount() {}

    void setAmount(float newAmount);

    int getID() {}

    std::string getDate() {}
};