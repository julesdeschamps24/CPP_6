#pragma once 

#include <string>
#include <iostream>
#include <stdexcept>



class Bureaucrat
{
public:
    Bureaucrat( std::string name = "Noname", int grade = 150);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void setGrade(int grade);

    void incrementGrade();
    void decremetnGrade();

    const std::string GradeTooHighException() const;
    class GradeTooLowExeception : public std::exception {
        public:
            const char* what() const throw();
    };

private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);