#include "ScalarConverter.hpp"
#include <string>

static bool manage_pseudo_literals(const std::string& str){
	std::string pseudo[] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
	int type = -1;

	for (int i = 0; i != 6; i++)
		if(pseudo[i] == str)
			type = i / 2;

	if(type == -1 )
		return (false);

	std::cout << type << std::endl;
	switch (type) {
		case 0:  // -
			std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
            break;

		case 1: // +
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
            break;
			
		case 2: // nan
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
            break;
	}
	return (true);
}


void ScalarConverter::convert(const std::string& str) {
	if(manage_pseudo_literals(str) == true)
		return;
}
