#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name), _grade(150) {
    if(grade < 1)
        GradeTooHighException(); 
    else if(grade > 150)
        GradeTooLowExeception();
    else
    {
        setGrade(grade);
        std::cout << *this << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) { *this = copy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if( this != &other)
        _grade = other._grade;
    return (*this);
}

const std::string& Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::setGrade( int grade ) { _grade = grade; }

void Bureaucrat::incrementGrade() {

}

void Bureaucrat::GradeTooHighException() const {
    std::cerr << "Error: "<< getName() << " grade range is too high" << std::endl;
    std::cerr << "Please insert grade between 1 and 150" << std::endl;
}
void Bureaucrat::GradeTooLowExeception() const {
    std::cerr << "Error: "<< getName() << " grade range is too low" << std::endl;
    std::cerr << "Please insert grade between 1 and 150" << std::endl;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << " bureaucrat grade is " << b.getGrade();
    return (out);
}