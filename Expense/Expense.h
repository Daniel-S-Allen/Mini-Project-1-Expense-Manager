#pragma once
#include <string>

class Expense {
private:
	float		  amount;
	std::string	  currency;
	std::string	  description;
	std::string	  date;
	static int	  numOfExpenses;
	unsigned long ID;

public:
	Expense(float a, std::string c, std::string d);
	void		convertCurrency(float newCurrency);
	float		getAmount();
	void		setAmount(float newAmount);
	int			getID();
	std::string getDate();
	void		convertCurrency(std::string newCurrency);
};