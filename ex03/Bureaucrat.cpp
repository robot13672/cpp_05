#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(0) 
{
	std::cout << "CONSTRUCTOR WITHOUT PARAMETERS CALLED" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.getName()), grade(copy.getGrade()) 
{
	std::cout << "COPPY CONSTRUCTOR CALLED" << std::endl; 
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "COPPY ASSIGNMENT CONSTRUCTOR CALLED" << std::endl;

	if (this == &copy)
		return *this;

	grade = copy.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) 
{ 
	std::cout << "CONSTRUCTOR WITH PARAMETERS CALLED" << std::endl;
	if (grade > 150 || grade < 0)
		this->grade = 0;
	else
		this->grade = grade;
};

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade < 150)
	{
		grade++;
		std::cout << "MADE GRADE INCRESSING" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (grade > 0)
	{
		grade--;
		std::cout << "MADE GRADE DESCRESSING" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low\n";
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat)
{
	stream << "Name is: " << bureaucrat.getName() << ", grade is: " << bureaucrat.getGrade() << std::endl;
	return stream;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << name << " cannot sign " << form.getName() << " form because " << e.what() << "\n";
		return;
		std::cout << name << " signed " << form.getName() << " form" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form)
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}