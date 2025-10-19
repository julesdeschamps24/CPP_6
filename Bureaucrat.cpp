#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name) {
    setGrade(grade);
    std::cout << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) { *this = copy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if( this != &other)
        _grade = other._grade;
    return (*this);
}

const std::string& Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::setGrade( int grade ) {
    if(grade < 1)
        throw GradeTooHighException(); 
    if(grade > 150)
        throw GradeTooLowExeception();
    _grade = grade; 
 }

void Bureaucrat::incrementGrade() {
    setGrade((_grade - 1));
}

const std::string Bureaucrat::GradeTooHighException() const {
    return ("Error: " +  getName() + " grade range is too high\nPlease insert grade between 1 and 150");
}
const char* Bureaucrat::GradeTooLowExeception::what() const throw() {
    return ("Error: grade range is too low\nPlease insert grade between 1 and 150");
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << " bureaucrat grade is " << b.getGrade();
    return (out);
}