#pragma once
#include <string>

class Expense {
private:
	static unsigned long numOfExpenses;

	double		  amount;
	std::string	  currency;
	std::string	  description;
	std::string	  date;
	unsigned long ID;

public:
	Expense(float a, std::string c, std::string d);
	Expense(float a, std::string c, std::string d, std::string dt);
	void		convertCurrency(float newCurrency);
	float		getAmount() const;
	void		setAmount(float newAmount);
	int			getID() const;
	std::string getDate() const;
	void		convertCurrency(std::string newCurrency);
	std::string getCurrency() const;
	std::string getDescription() const;
	bool operator==(const Expense& other) const;
};