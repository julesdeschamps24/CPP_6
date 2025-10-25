#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
    public:
        AForm(std::string name = "Noname", const int sign_grade = 150, const int execute_grade = 150);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

		const std::string& getName() const;

		int getSignGrade() const;
		int getExecuteGrade() const;

		void setGradeToSign(bool sign);

		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void executionCheck(Bureaucrat const & executor) const;

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

		class BureaucratGradeLowerExecuteGrade : public std::exception {
			public:
				const char* what() const throw();
			
		};

		class GradeNotSign : public std::exception {
			public:
				const char* what() const throw();
		};

    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
