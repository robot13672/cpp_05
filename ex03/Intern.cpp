#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { };

Intern::Intern(const Intern& copy) { *this = copy; };

Intern& Intern::operator=(const Intern& copy) { (void)copy; return *this; };

Intern::~Intern() { };

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = { "presidential Pardon", "robotomy request", "shrubbery creation" };
	
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			if (i == 0)
			{
				std::cout << "Intern created " << forms[0] << std::endl;
				return new PresidentialPardonForm(target);
			}
			else if (i == 1)
			{
				std::cout << "Intern created " << forms[1] << std::endl;
				return new RobotomyRequestForm(target);
			}
			else if (i == 2)
			{
				std::cout << "intern created " << forms[2] << std::endl;
				return new ShrubberyCreationForm(target);
			}
		}
	}
	std::cout << "No such form exists: " << name << std::endl;
	return NULL;
}


