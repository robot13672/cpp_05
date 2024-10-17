#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern unnamedIntern;
	Bureaucrat bill("Bill", 1);
	AForm *form1 = unnamedIntern.makeForm("shrubbery creation", "42");
	AForm *form2 = unnamedIntern.makeForm("robotomy request", "Cedwic");
	AForm *form3 = unnamedIntern.makeForm("presidential Pardon", "Cem");
	AForm *form4 = unnamedIntern.makeForm("world domination", "The world");
	std::cout << "Form 1: " << *form1 << std::endl;
	std::cout << "Form 2: " << *form2 << std::endl;
	std::cout << "Form 3: " << *form3 << std::endl;
	if (!form4)
		std::cout << "Form 4: * doesn't exist! *" << std::endl;
	bill.signForm(*form1);
	bill.signForm(*form2);
	bill.signForm(*form3);
	bill.executeForm(*form1);
	bill.executeForm(*form2);
	bill.executeForm(*form3);
	delete form1;
	delete form2;
	delete form3;
}