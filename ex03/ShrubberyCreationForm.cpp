#include "ShrubberyCreationForm.hpp"
#include <AForm.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm("Shrubbery", 145, 137), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { 
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const { return (_target); }

const char* ShrubberyCreationForm::FileErr::what() const throw () {
	return ("Error:");
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::executionCheck(executor);

	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile.is_open()) 
		throw FileErr();
	outfile << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\\n";
    outfile.close();
}
