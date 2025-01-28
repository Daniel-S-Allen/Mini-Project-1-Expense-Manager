#include "Expense.h"
#include <ctime>
#include <string>

Expense::Expense(float amount, std::string currency, std::string description)
	: amount(amount), currency(currency), description(description), ID(numOfExpenses) {
	// Set ID of expense

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

float Expense::getAmount() const {
	return this->amount;
}

void Expense::setAmount(float newAmount) {
	amount = newAmount;
}

int Expense::getID() const {
	return this->ID;
}

std::string Expense::getDate() const {
	return this->date;
}
std::string Expense::getCurrency() const{
	return this->currency;
}
unsigned long Expense::numOfExpenses = 0;