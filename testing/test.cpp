#include "../Expense/Expense.h"
#include "../database/category.h"
#include "../database/file.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <string>

namespace Testing {
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
		DatabaseIO::writeToFile("Serialization1.expenses", root);
		Category test = DatabaseIO::readFromFile("Serialization1.expenses");
		assert(test == root);
		Category fail("Not Equal");
		test.addCategory(fail);
		assert(test != root);
	}

	void testNumbers() {
		Category root("Root");
		Expense	 zero(0, "CAD", "Zero");
		Expense	 inf(INFINITY, "CAD", "Infinity");
		Expense	 negative(-1000, "CAD", "Negative");
		assert(zero.getAmount() == 0);
		assert(inf.getAmount() == INFINITY);
		assert(negative.getAmount() == -1000);
		root.addEntry(zero);
		root.addEntry(inf);
		root.addEntry(negative);
		DatabaseIO::writeToFile("Numbers.expenses", root);
		Category test = DatabaseIO::readFromFile("Numbers.expenses");
		assert(test.expenses[0] == zero);
		assert(test.expenses[1] == inf);
		assert(test.expenses[2] == negative);
	}

	void testMalformedInput() {
		Category root("Root");
		Category linebreak("Malf\normed");
		root.addCategory(linebreak);
		// Fails due to C++ issues, not code issues
		// Category nullterm("Cat\0egory");
		// root.addCategory(nullterm);
		DatabaseIO::writeToFile("Malformed.expenses", root);
		Category result = DatabaseIO::readFromFile("Malformed.expenses");
		assert(result.subcategories[0].name == std::string("Malf\normed"));
		// assert(result.subcategories[1].name == std::string("Cat\\0egory"));
	}

	void test() {
		testSerialization();
		testNumbers();
		testMalformedInput();
		std::cout << "All tests passed!\n";
	}
} // namespace Testing