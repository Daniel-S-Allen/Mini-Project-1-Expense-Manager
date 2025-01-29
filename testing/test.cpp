// #include "../Expense/Expense.h"
#include "../database/file.h"
#include <cstdlib>

void testSerialization() {
	Category root("Root");
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		Category tempCategory(std::format("Category {}", i));
		for (int j = 0; j < rand() % 5 + 1; j++) {
			Expense tempEntry((rand() % 1000) / 100.0, "CAD", std::format("Entry {}", j));
			tempCategory.addEntry(tempEntry);
		}
		root.addCategory(tempCategory);
	}
	DatabaseIO::writeToFile("Write.expenses", root);
	Category test = DatabaseIO::readFromFile("Write.expenses");
	DatabaseIO::writeToFile("Read.expenses", test);
}