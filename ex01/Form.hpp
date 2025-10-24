#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
    public:
        Form(std::string name = "Noname", const int sign_grade = 150, const int execute_grade = 150);
        Form(const Form& copy);
        Form& operator=(const Form& other);
        ~Form();

		const std::string& getName() const;

		int getSignGrade() const;
		int getExecuteGrade() const;

		void setGradeToSign(bool sign);

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class BureaucratGradeLowerSignGrade : public std::exception {
			public:
				const char* what() const throw();
		};
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
};

std::ostream& operator<<(std::ostream& out, const Form& f);
