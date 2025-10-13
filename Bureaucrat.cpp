#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(0) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) { *this = copy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if( this != &other)
        _grade = other._grade;
}

Bureaucrat::~Bureaucrat() {}