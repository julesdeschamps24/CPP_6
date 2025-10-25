#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

typedef AForm* (*Creator)(const std::string);

static AForm* createShrubbery(const std::string target) { return (new ShrubberyCreationForm(target)); }
static AForm* createRobotomy(const std::string target) { return (new RobotomyRequestForm(target)); }
static AForm* createPresidential(const std::string target) { return (new PresidentialPardonForm(target)); }

AForm* Intern::makeForm(std::string name, std::string target) {
	static const std::string str_tab[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static Creator c[3] = {&createShrubbery, &createRobotomy, &createPresidential};

	for (int i = 0; i != 3; i++)
	{
		if(name == str_tab[i])
			return (c[i](target));
	}
	
	throw UnknowName();
}

const char* Intern::UnknowName::what() const throw() {
	return ("Error: Unkmown name passed as parameter");
}
