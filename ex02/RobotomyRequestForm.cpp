#include "RobotomyRequestForm.hpp"
#include <AForm.hpp>
#include <unistd.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm("Robotomy", 72, 45), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) { 
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const { return (_target); }

const char* RobotomyRequestForm::RobotomizeFlop::what() const throw() {
	return ("Robotomy failed, flop flop flop");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::executionCheck(executor);
	
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;

	std::srand(getpid());
	if(std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		throw RobotomizeFlop();
}
