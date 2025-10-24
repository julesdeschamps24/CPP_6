#include "Form.hpp"

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) 
	: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
		if(_grade_to_exec < 1 || _grade_to_sign < 1)
			throw  GradeTooHighException();
		if(_grade_to_exec > 150 || _grade_to_sign > 150)
			throw  GradeTooLowException();
	}

Form::Form(const Form& copy) 
: _name(copy._name), _is_signed(false), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) { 
	*this = copy;
	if(_grade_to_exec < 1 || _grade_to_sign < 1)
		throw  GradeTooHighException();
	if(_grade_to_exec > 150 || _grade_to_sign > 150)
		throw  GradeTooLowException();
}

Form& Form::operator=(const Form& other) {
	if(this != &other)
		_is_signed = other._is_signed;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const { return (_name); }
int Form::getSignGrade() const { return (_grade_to_sign); }
int Form::getExecuteGrade() const { return (_grade_to_exec); }

void Form::setGradeToSign(bool sign) { _is_signed =  sign; }

void Form::beSigned(const Bureaucrat& b) {
	if(b.getGrade() <= getSignGrade())
	{
		std::cout << b.getName() << " signed " << getName() << std::endl;
		setGradeToSign(true);
	}
	else
		throw BureaucratGradeLowerSignGrade();
}


const char* Form::GradeTooHighException::what () const throw() { 
    return ("Error: one of the Form grade is too high\nPlease insert grade between 1 and 150");
}

const char* Form::GradeTooLowException::what () const throw() { 
    return ("Error: one of the Form grade is too low\nPlease insert grade between 1 and 150");
}

const char* Form::BureaucratGradeLowerSignGrade::what () const throw() { 
    return ("Bureaucrat grade is lower than sign grade");
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() << " Form grade to sign is " << f.getSignGrade() \
		<< " and grade to execute is " << f.getExecuteGrade();
    return (out);
}
