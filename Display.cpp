#include "Display.h"


std::vector<Expense> filterByKeyword(const std::vector<Expense>& expenses, const std::string& keyword)
{
    std::vector<Expense> filtered;
    for (const auto& expense : expenses)
    {
        if (expense.getDescription().find(keyword) != std::string::npos)
        {
            filtered.push_back(expense);
        }
    }
    return filtered;
}


void sortByID(std::vector<Expense>& expenses)
{
    for (size_t i = 0; i < expenses.size() - 1; i++)
    {
        for (size_t j = i + 1; j < expenses.size(); j++)
        {
            if (expenses[i].getID() > expenses[j].getID())
            {
                std::swap(expenses[i], expenses[j]);
            }
        }
    }
}

void sortByTime(std::vector<Expense>& expenses)
{
    for (size_t i = 0; i < expenses.size() - 1; i++)
    {
        for (size_t j = i + 1; j < expenses.size(); j++)
        {
            if (expenses[i].getTime() > expenses[j].getTime())
            {
                std::swap(expenses[i], expenses[j]);
            }
        }
    }
}

void sortByAmount(std::vector<Expense>& expenses)
{
    for (size_t i = 0; i < expenses.size() - 1; i++)
    {
        for (size_t j = i + 1; j < expenses.size(); j++)
        {
            if (expenses[i].getAmount() > expenses[j].getAmount())
            {
                std::swap(expenses[i], expenses[j]);
            }
        }
    }
}



void displayMenu()
{

	int userSelection = 0;
	std::cout << "Select Display Option" << std::endl;
	std::cin >> userSelection;
	
    switch (userSelection)
    {
    case 1:
        displayExpense();
        break;
    }
}

std::vector<Expense> sortExpensesByID(std::vector<Expense> expenses)
{
    std::sort(expenses.begin(), expenses.end(), [](const Expense& a, const Expense& b)
        {
            return a.getID() < b.getID();
        });
    return expenses; // Return the sorted vector
}

void displayExpenses(std::vector<Expense>& expenses)
{
    char userSelection;
    std::cout << "Do you want sorted expenses? (y/n)" << std::endl;
    std::cin >> userSelection;
    if (userSelection == 'y')
    {
        sortDisplay();
    }

    for (const auto& expense : expenses)
    {
        std::cout << "Expense ID: " << expense.getID() << std::endl;
        std::cout << "Amount: " << expense.getAmount() << std::endl;
        std::cout << "Time: " << expense.getTime() << std::endl;
    }

 



}

void sortDisplay()
{
    int userSelection = 0;
    std::cout << "How do you want to sort the expenses?" << std::endl;
    
    std::cout << "1.sort expense by id" << std::endl;
    std::cout << "2.sort expense by time" << std::endl;
    std::cout << "3.sort expense by amount" << std::endl;
    std::cout << "4.display expense by keyword" << std::endl;
    std::cin >> userSelection;

    switch (userSelection)
    {
    case 1:
        sortByID(expenses);
        break;
    case 2:
        sortByTime(expenses);
        break;
    case 3:
        sortByAmount(expenses);
        break;
    case 4:
        std::string keyword;
        std::cout << "Enter keyword to filter by: ";
        std::cin >> keyword;
        expenses = filterByKeyword(expenses, keyword);
        break;
    default:
        std::cout << "Invalid selection. Displaying unsorted expenses." << std::endl;
    }

    displayExpenses(expenses);
}


