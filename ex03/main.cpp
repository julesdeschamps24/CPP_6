#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try {
        Intern someIntern;

        AForm* sh = someIntern.makeForm("shrubbery creation", "garden");
        AForm* robot = someIntern.makeForm("robotomy request", "Bender");
        AForm* president = someIntern.makeForm("presidential pardon", "Alice");

        Bureaucrat boss("Boss", 1);
        boss.signForm(*sh);
        boss.executeForm(*sh);

		std::cout << std::endl;

		boss.signForm(*robot);
		boss.executeForm(*robot);

		std::cout << std::endl;

        delete sh;
        delete robot;
        delete president;

        someIntern.makeForm("bad", "nobody");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}
