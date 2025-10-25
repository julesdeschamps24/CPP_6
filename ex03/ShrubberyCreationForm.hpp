#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	 public:
		ShrubberyCreationForm(std::string target = "no target");
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		const std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;

		class FileErr : public std::exception {
			public:
				const char* what() const throw();
		};
	 private:
		const std::string _target;		
};
