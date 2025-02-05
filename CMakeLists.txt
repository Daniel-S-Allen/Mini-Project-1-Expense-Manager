cmake_minimum_required(VERSION 3.10.0)
project(ExpenseManager VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PREFIX_PATH /usr/bin;/usr/include;${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
	UserInput/userinput.cpp
    Expense/Expense.cpp
	Expense/ExpenseManager.cpp
	Display.cpp
	testing/test.cpp
)
set(NAME "ExpenseManager")
add_executable(${NAME} ${SOURCES})
target_include_directories(${NAME}
    PRIVATE
        Expense/
		database/
)
#target_compile_options(${NAME} PRIVATE -fsanitize=address)
#target_link_options(${NAME} PRIVATE -fsanitize=address)