#include "PresidentialPardonForm.hpp"
#include <AForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("President", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm("President", 25, 5), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) { 
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const { return (_target); }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::executionCheck(executor);
	
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
