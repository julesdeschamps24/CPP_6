#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
		std::cout << "Test 1: Bureaucrat grade too low in constructor\n" << std::endl;
		Bureaucrat a("Jules", 160);
		a.incrementGrade();
    } catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
    }
	
    try {
		std::cout << "\nTest 2: Form grade too low in constructor\n" << std::endl;
		Form f("Form", 151, 20);
    } catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
    }
    try {
		std::cout << "\nTest 2 bis: Form grade too low in constructor\n" << std::endl;
		Form f("Form", 20, 200);
    } catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
    }


	try {
		std::cout << "\nTest 3: signForm test:" << std::endl;
		Bureaucrat high("CEO", 1);
		Bureaucrat low("cashier", 140);
		Form f("Form", 10, 20);

		std::cout << f << std::endl;

		std::cout << "\nHigh grade Bureaucrat:" << std::endl;
		high.signForm(f);

		std::cout << "\nLow grade Bureaucrat:" << std::endl;
		low.signForm(f);


	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
