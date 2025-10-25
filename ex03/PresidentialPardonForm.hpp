#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	 public:
		PresidentialPardonForm(std::string target = "no target");
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		const std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;

	private:
		const std::string _target;		
};
