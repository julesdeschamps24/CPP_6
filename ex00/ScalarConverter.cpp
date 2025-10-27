#include "ScalarConverter.hpp"
#include <string>

static bool manage_pseudo_literals(const std::string& str){
	const std::string pseudo[] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
	int type = -1;

	for (int i = 0; i != 6; i++)
		if(pseudo[i] == str)
			type = i / 2;

	if(type == -1 )
		return (false);

	switch (type) {
		case 0:  // -
			std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -inff\n";
            std::cout << "double: -inf" << std::endl;
            break;

		case 1: // +
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +inff\n";
            std::cout << "double: +inf" << std::endl;
            break;
			
		case 2: // nan
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan" << std::endl;
            break;
	}
	return (true);
}

static bool manage_char(const std::string& str, int size) {
	if(!(size == 1 && ((str[0] >= 32 && str[0] < 48) || (str[0] <= 126 && str[0] >= 58))))
		return (false);

	std::cout << "char: " << str 
	<< "\nint: " << static_cast<int>(str[0])
	<< "\nfloat: " << static_cast<float>(str[0])
	<< "\ndouble: " << static_cast<double>(str[0]) << std::endl;
	return (true);
}

void ScalarConverter::convert(const std::string& str) {
	if(manage_pseudo_literals(str) == true)
		return;

	int size = str.size();

	if(manage_char(str, size) == true)
		return;
}
