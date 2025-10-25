#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::setGrade( int grade ) {
    if(grade < 1)
        throw GradeTooHighException(); 
    if(grade > 150)
        throw GradeTooLowException();
    _grade = grade; 
 }

void Bureaucrat::incrementGrade() {
    setGrade((_grade - 1));
}

void Bureaucrat::decrementGrade() {
    setGrade((_grade + 1));
}

void Bureaucrat::signForm(AForm& f) { 
	try {
		f.beSigned(*this); 
		std::cout << getName() << " signed " << f.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << getName() << " couldn't sign " << f.getName() 
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	form.execute(*this);
	std::cout << getName() << " executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Error: grade range is too high\nPlease insert grade between 1 and 150");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Error: grade range is too low\nPlease insert grade between 1 and 150");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << " bureaucrat grade is " << b.getGrade();
    return (out);
}
