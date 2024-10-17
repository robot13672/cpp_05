#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) 
{ 
	std::cout << "CONSTRUCTOR WITHOUT PARAMETERS CALLED" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy.getName(), 72, 45)
{
	std::cout << "COPPY CONSTRUCTOR CALLED" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	std::cout << "COPPY ASSIGNMENT CONSTRUCTOR CALLED" << std::endl;
	target = copy.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "CONSTRUCTOR WITH PARAMETERS CALLED" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
    if (b.getGrade() >= getGradeExec() && getSigned())
    {
        srand(time(NULL)); 
        if (rand() % 2)
        {
            std::cout << " * Drilling Noise * " << std::endl;
            std::cout << target << " has been robotomized by " << b.getName() << "!" << std::endl;
        }
        else
            std::cout << b.getName() << " tried to robotomize " << target << " but failed!" << std::endl;
    }
    else
    {
        if (!getSigned())
            std::cout << "This form '" << getName() << "' is not signed!" << std::endl;
        else
            throw AForm::GradeTooLowException();
    }
}