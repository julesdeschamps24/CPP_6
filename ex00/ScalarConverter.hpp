#pragma once 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <climits>
#include <iomanip>

class ScalarConverter
{
	 public:
		static void convert(const std::string& str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};
