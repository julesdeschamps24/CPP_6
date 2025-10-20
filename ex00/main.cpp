#include "Bureaucrat.hpp"

int main()
{
    try {
    std::cout << "Test 1: grade too low in constructor\n" << std::endl;
    Bureaucrat a("Jules", 160);
    a.incrementGrade();
    } catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
    }

    try {
    std::cout << "\nTest 2: grade too high in constructor\n" << std::endl;
    Bureaucrat a("Jules", 0);
    a.incrementGrade();
    } catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
    }

    try {
    std::cout << "\nTest 3: grade too low because of decrementation\n" << std::endl;
    Bureaucrat a("Jules", 148);
    a.decrementGrade();
    std::cout << a << std::endl;
    a.decrementGrade();
    std::cout << a << std::endl;
    a.decrementGrade();
    std::cout << a << std::endl;
    } catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
    }

    try {
    std::cout << "\nTest 4: grade too high because of incrementation\n" << std::endl;
    Bureaucrat a("Jules", 2);
    a.incrementGrade();
    std::cout << a << std::endl;
    a.incrementGrade();
    std::cout << a << std::endl;
    a.incrementGrade();
    std::cout << a << std::endl;
    } catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
    }
    return 0;
}

