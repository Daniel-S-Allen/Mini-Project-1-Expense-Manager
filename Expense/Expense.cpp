#include "Expense.h"
#include <ctime>
#include <string>

Expense::Expense(float amount, std::string currency, std::string description)
	: amount(amount), currency(currency), description(description), ID(numOfExpenses) {

	numOfExpenses++;

	// Set date to current date
	std::time_t t	= std::time(0); // get time now
	std::tm	   *now = std::localtime(&t);

	date = std::to_string(now->tm_year + 1900) + '-' + std::to_string(now->tm_mon + 1) + "-" +
		   std::to_string(now->tm_mday);
};

Expense::Expense(float amount, std::string currency, std::string description, std::string date)
	: amount(amount), currency(currency), description(description), ID(numOfExpenses), date(date) {

	numOfExpenses++;
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
std::string Expense::getDescription() const {
	return description;
}
bool Expense::operator==(const Expense& other) const{
	if(this->amount != other.getAmount()){
		return false;
	}
	//TODO convert currency to compare
	if(this->currency != other.currency){
		return false;
	}
	if(this->description != other.description){
		return false;
	}
	if(this->date != other.date){
		return false;
	}
	//TODO comparing by ID is bugged since it increments so there may be no duplicates
	// if(this->ID != other.ID){
	// 	return false;
	// }
	return true;
}
unsigned long Expense::numOfExpenses = 0;