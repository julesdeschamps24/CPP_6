#pragma once 

#include <string>
#include <iostream>

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

    void GradeTooHighException() const;
    void GradeTooLowExeception() const;

private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);