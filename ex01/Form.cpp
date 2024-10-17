#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) {}

Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), gradeRequiredToSign(copy.gradeRequiredToSign), gradeRequiredToExecute(copy.gradeRequiredToExecute) {
    std::cout << "Copy constructor for Form called" << std::endl;
}

Form& Form::operator=(const Form& copy) 
{
    if (this == &copy)
        return *this;
    return *this;
}

Form::~Form() 
{
    std::cout << "Destructor for Form called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << getName() << " has been initialized." << std::endl;
}

std::string Form::getName() const {
    return name;
}

bool Form::getSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeRequiredToSign()) {
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
    std::cout << "Form " << this->getName() << " is signed by " << bureaucrat.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Form& form) {
    stream << form.getName() << " form is " << (form.getSigned() ? "signed" : "not signed") << std::endl;
    stream << "Grade required to sign: " << form.getGradeRequiredToSign() << std::endl;
    stream << "Grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
    return stream;
}