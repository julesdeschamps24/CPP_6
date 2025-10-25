#include "AForm.hpp"

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) 
: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
		if(_grade_to_exec < 1 || _grade_to_sign < 1)
			throw  GradeTooHighException();
		if(_grade_to_exec > 150 || _grade_to_sign > 150)
			throw  GradeTooLowException();
	}

AForm::AForm(const AForm& copy) 
: _name(copy._name), _is_signed(false), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) { 
	*this = copy;
	if(_grade_to_exec < 1 || _grade_to_sign < 1)
		throw  GradeTooHighException();
	if(_grade_to_exec > 150 || _grade_to_sign > 150)
		throw  GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
	if(this != &other)
		_is_signed = other._is_signed;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return (_name); }
int AForm::getSignGrade() const { return (_grade_to_sign); }
int AForm::getExecuteGrade() const { return (_grade_to_exec); }

void AForm::setGradeToSign(bool sign) { _is_signed =  sign; }

void AForm::beSigned(const Bureaucrat& b) {
	if(b.getGrade() <= getSignGrade())
		setGradeToSign(true);
	else
		throw BureaucratGradeLowerSignGrade();
}

void AForm::executionCheck(Bureaucrat const & executor) const {
	if(_is_signed == false)
		throw GradeNotSign();
	if(executor.getGrade() > _grade_to_exec)
		throw BureaucratGradeLowerExecuteGrade();
}


const char* AForm::GradeTooHighException::what () const throw() { 
    return ("Error: one of the AForm grade is too high\nPlease insert grade between 1 and 150");
}

const char* AForm::GradeTooLowException::what () const throw() { 
    return ("Error: one of the AForm grade is too low\nPlease insert grade between 1 and 150");
}

const char* AForm::BureaucratGradeLowerSignGrade::what () const throw() { 
    return ("Bureaucrat grade is lower than sign grade");
}

const char* AForm::BureaucratGradeLowerExecuteGrade::what () const throw() { 
    return ("Bureaucrat grade is lower than execute grade");
}

const char* AForm::GradeNotSign::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << f.getName() << " AForm grade to sign is " << f.getSignGrade() \
		<< " and grade to execute is " << f.getExecuteGrade();
    return (out);
}
