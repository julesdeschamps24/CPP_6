#include "Intern.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

AForm* Intern::makeForm(std::string name, std::string target) {
	if(name == "shrubbery creation")
		return(new ShrubberyCreationForm(target));
	if(name == "robotomy request")
		return (new RobotomyRequestForm(target));
	if(name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	throw UnknowName();
}

const char* Intern::UnknowName::what() const throw() {
	return ("Unkmown name passed as parameter");
}
