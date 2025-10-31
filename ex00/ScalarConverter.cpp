#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool manage_pseudo_literals(const std::string& str){
	const std::string pseudo[] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
	int type = -1;

	for (int i = 0; i != 6; i++)
		if(pseudo[i] == str)
			type = i / 2;

	if(type == -1 )
		return (false);

	type *= 2;
	std::cout << "char: impossible\n" 
	<< "int: impossible\n"
	<< "float: " << pseudo[type]
	<< "\ndouble: " << pseudo[type + 1] << std::endl;
	return (true);
}

static bool manage_char(const std::string& str, int size) {
	if(!(size == 1 && ((str[0] >= 32 && str[0] < 48) || (str[0] <= 126 && str[0] >= 58))))
		return (false);

	std::cout << "char: " << str 
	<< "\nint: " << static_cast<int>(str[0])
	<< "\nfloat: " << static_cast<float>(str[0]) << ".0f"
	<< "\ndouble: " << static_cast<double>(str[0]) << ".0" <<std::endl;
	return (true);
}

static bool is_zero(const std::string& str)
{
	if(str[0] != '0')
			return (false);
	return (true);
}

static void print_decimals(const std::string& str, int nb_dec, int size)
{
	float float_nb = std::strtof(str.c_str(), NULL);
	
	size--;
	if(str[size] == 'f')
		size--;
	std::cout << "float: ";
	if(errno != 0)
	{
		std::cout << "erange errror" << std::endl;
		errno = 0;
	}
	else
	{
		if(nb_dec <= 0 || (size - nb_dec) == 6)
			std::cout << std::fixed << std::setprecision(1) << float_nb << "f" << std::endl;
		else
		{
			if(is_zero(&str[size - nb_dec + 1]) == true)
				std::cout << std::fixed << std::setprecision(1) << float_nb << "f" << std::endl;
			else
				std::cout << float_nb << "f" << std::endl;
		}
	}

	double double_nb = std::strtod(str.c_str(), NULL);
	
	size--;
	if(str[size] == 'f')
		size--;
	std::cout << "double: ";
	if(errno != 0)
	{
		std::cout << "erange errror" << std::endl;
		errno = 0;
	}
	else
	{
		if(nb_dec <= 0 || (size - nb_dec) == 12)
			std::cout << std::fixed << std::setprecision(1) << double_nb << std::endl;
		else
		{
			if(is_zero(&str[size - nb_dec + 1]) == true)
				std::cout << std::fixed << std::setprecision(1) << double_nb << std::endl;
			else
				std::cout << double_nb << std::endl;
		}
	}
}

static void print_num(const std::string& str, int size)
{
	long int_nb;
	int nb_of_decimal = 0;
	char* end = 0;

	int_nb = strtol(str.c_str(), &end, 10);
	if(end != 0)
	{
		nb_of_decimal = strlen(end) - 1;
		if(str[size - 1] == 'f')
			nb_of_decimal--;
	}
	if(errno != 0 || int_nb < INT_MIN || int_nb > INT_MAX)
	{
		std::cout << "char: non displayable\n";
		std::cout << "int: erange error\n";
		errno = 0;
	}
	else
	{
		std::cout << "char: ";
		if(int_nb < 32 || int_nb > 126)
			std::cout << "non displayable\n";
		else 
			std::cout << static_cast<char>(int_nb) << "\n";
		std::cout << "int :" << static_cast<int>(int_nb) << "\n";
	}
	print_decimals(str, nb_of_decimal, size);
}

static bool manage_decimals(const std::string& str, int size, int index)
{
	if(str[index] == '\0' || str[index] == 'f')
		return (false);

	while(index != size)
	{
		if(std::isdigit(str[index]) == false)
		{
			if(str[index] != 'f')
				return (false);
			else
			{
				print_num(str, size);
				return (true);
			}
		}
		index++;
	}
	print_num(str, size);
	return (true);
}

static bool manage_number(const std::string& str, int size)
{
	int i = 0;

	if(str[0] == '+' || str[0] == '-')
		i++;
	while(i != size)
	{
		if(std::isdigit(str[i]) == false)
		{
			if(str[i] == '.' && i >= 1)
				return (manage_decimals(str, size, i + 1));
			else
				return (false);
		}
		i++;
	}
	print_num(str, size);
	return (true);
}

void ScalarConverter::convert(const std::string& str) {
	int size = str.size();
	
	if(size == 0)
	{
		std::cerr << "Error: wrong input" << std::endl;
		return;
	}

	if(manage_pseudo_literals(str) == true)
		return;

	if(manage_char(str, size) == true)
		return;

	if(manage_number(str, size) == true)
		return;

	std::cerr << "Error: wrong input" << std::endl;
}
