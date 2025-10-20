#pragma once

#include "iostream"
#include "string"

class Form {
    public:
        Form();
        Form(const Form& copy);
        Form operator=(const Form& other);
        ~Form();
    private:
        const std::string& _name;
        bool _is_signed;
        const int _sign_grade;
        const int _execute_grade;
};
