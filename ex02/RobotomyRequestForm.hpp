#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	 public:
		RobotomyRequestForm(std::string target = "no target");
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		const std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;

		class RobotomizeFlop : public std::exception {
			public:
				const char* what() const throw ();

		};

	private:
		const std::string _target;		
};
