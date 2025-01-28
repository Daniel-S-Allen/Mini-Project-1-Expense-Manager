#include "Expense.h"
#include <ctime>
#include <string>

Expense::Expense(float amount, std::string currency, std::string description): amount(amount), currency(currency), description(description) {
	// Set ID of expense
	ID = numOfExpenses;
	numOfExpenses++;

	// Set date to current date
	std::time_t t	= std::time(0); // get time now
	std::tm	   *now = std::localtime(&t);

	date = std::to_string(now->tm_year + 1900) + '-' + std::to_string(now->tm_mon + 1) + "-" +
		   std::to_string(now->tm_mday);
};

void Expense::convertCurrency(std::string newCurrency) {
	currency = newCurrency;
	// TODO: Convert amount
}

float Expense::getAmount() {
	return this->amount;
}

void Expense::setAmount(float newAmount) {
	amount = newAmount;
}

int Expense::getID() {
	return this->ID;
}

std::string Expense::getDate() {
	return this->date;
}