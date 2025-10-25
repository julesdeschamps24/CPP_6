#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
	 public:
		AForm* makeForm(std::string name, std::string target);
		class UnknowName : public std::exception {
			public:
				const char* what() const throw();
		};
};
