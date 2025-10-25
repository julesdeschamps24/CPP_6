#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>

int main()
{
	try {
		std::cout << "Test 1: grade not signed" << std::endl;
		Bureaucrat b("Jules", 100);
		ShrubberyCreationForm sh("tree");
		sh.execute(b);
		std::cout << sh << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Test 2: grade too low to be executed" << std::endl;
		Bureaucrat b("Jules", 140);
		ShrubberyCreationForm sh("tree");
		sh.beSigned(b);
		sh.execute(b);
		std::cout << sh << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Test 3: ShrubberyCreationForm" << std::endl;
		Bureaucrat b("Jules", 130);
		ShrubberyCreationForm sh("tree");
		sh.beSigned(b);
		sh.execute(b);
		std::cout << sh << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Test 4: RobotomyRequestForm" << std::endl;
		Bureaucrat b("Jules", 30);
		RobotomyRequestForm robot("droll");
		robot.beSigned(b);
		robot.execute(b);
		std::cout << robot << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Test 5: PresidentialPardonForm" << std::endl;
		Bureaucrat b("Jules", 5);
		PresidentialPardonForm president("blud");
		president.beSigned(b);
		president.execute(b);
		std::cout << president << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Test 6: Bureaucrat execution + fail exec" << std::endl;
		Bureaucrat b("Jules", 5);
		PresidentialPardonForm president("blud");
		RobotomyRequestForm robot("droll");
		ShrubberyCreationForm sh("tree");

		president.beSigned(b);
		robot.beSigned(b);

		b.executeForm(president);
		b.executeForm(robot);
		b.executeForm(sh);
		std::cout << president << std::endl;
	} catch (std::exception & e) {
	std::cerr << e.what() << std::endl;
	}

	return (0);
}
