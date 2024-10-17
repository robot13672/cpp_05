#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentalPardonForm", 25, 5) { };

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), 25, 5)
{
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	this->target = copy.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { };

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	if (b.getGrade() <= getGradeExec() && getSigned())
	{
		std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		std::cout << b.getName() << " executed " << getName() << std::endl;
	}
	else
	{
		if (!getSigned())
			std::cout << "This form " << getName() << " is not signed!" << std::endl;
		else
			throw AForm::GradeTooLowException();
	}
}