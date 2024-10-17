#include "AForm.hpp"

AForm::AForm() : name("NoName"), isSigned(false), gradeSign(150), gradeExec(150) { };

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec) { *this = copy; };

AForm& AForm::operator=(const AForm& copy)
{
	isSigned = copy.isSigned;
	return *this;
}

AForm::~AForm() { };

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	isSigned = false;
	if (gradeExec < 1 || gradeSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

const std::string AForm::getName() const
{
	return (name);
}

int AForm::getGradeSign() const
{
	return (gradeSign);
}

int AForm::getGradeExec() const
{
	return (gradeExec);
}

bool AForm::getSigned() const
{
	return (isSigned);
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < gradeSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
	std::cout << "Form " << this->getName() << " is signed by " << b.getName() << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& stream, AForm& AForm)
{
	stream << AForm.getName() << " AForm is " << (AForm.getSigned() ? "signed" : "not signed") << std::endl;
	stream << "Grade required to sign it: " << AForm.getGradeSign() << std::endl;
	stream << "Grade required to execute it: " << AForm.getGradeExec() << std::endl;
	return(stream);
}