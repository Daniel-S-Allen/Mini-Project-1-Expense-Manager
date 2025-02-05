#pragma once
#include <string>
#include <sstream>
namespace Utilities {
	std::string escape(std::string input) {
		for (int start = 0; start < input.size(); start++) {
			if (input[start] == '\n') {
				input.replace(start, 1, "\\n");
			}
		}
		return input;
	}

	std::string unescape(std::string input) {
		for (int start = 0; start < input.size(); start++) {
			if (input.substr(start, 2) == "\\n") {
				input.replace(start, 2, "\n");
			}
		}
		return input;
	}

	static constexpr char PADDING = '\t';

	/**
	 * @brief Generate a string of characters of a specific length, used for padding
	 *
	 * @param count The number of characters to use
	 * @return std::string
	 */
	static std::string padding(int count) {
		std::string		  output;
		std::stringstream out(output);
		for (int i = 0; i < count; i++) {
			out << PADDING;
		}
		return out.str();
	}

	/**
	 * @brief Generate a string of characters of a specific length, used for padding
	 *
	 * @param c The character to use as padding
	 * @param count The number of characters to use
	 * @return std::string
	 */
	static std::string padding(char c, int count) {
		std::string		  output;
		std::stringstream out(output);
		for (int i = 0; i < count; i++) {
			out << c;
		}
		return out.str();
	}

	/**
	 * @brief Return a string with the padding trimmed from the left side
	 *
	 * @param input The input string
	 * @return std::string
	 */
	static std::string trim_left(std::string input) {
		return input.substr(input.find_first_not_of(PADDING));
	}
} // namespace Utilities