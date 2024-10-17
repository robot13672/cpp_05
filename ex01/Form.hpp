#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:
    Form();
    Form(const Form& copy);
    Form& operator=(const Form& copy); // Оставим как приватный для запрета присваивания
    ~Form();

    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    std::string getName() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    bool getSigned() const;
    void beSigned(class Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif