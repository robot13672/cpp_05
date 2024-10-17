#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
   Bureaucrat bill("Bill", 150);
	Bureaucrat jackson("Jackson", 100);
	Bureaucrat emily("Emily", 50);
	Bureaucrat frank("Frank", 25);
	Bureaucrat caroline("Caroline", 1);
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "These are our bureaucrats:" << std::endl;
	std::cout << bill << std::endl;
	std::cout << jackson << std::endl;
	std::cout << emily << std::endl;
	std::cout << frank << std::endl;
	std::cout << caroline << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	ShrubberyCreationForm form1("home");
	ShrubberyCreationForm form2(form1);
	RobotomyRequestForm form3("Bender");
	RobotomyRequestForm form4(form3);
	PresidentialPardonForm form5("Santa");
	PresidentialPardonForm form6;
	form6 = form5;
	std::cout << "These are our forms:" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl << std::endl;

	std::cout << form3 << std::endl;
	std::cout << form4 << std::endl << std::endl;

	std::cout << form5 << std::endl;
	std::cout << form6 << std::endl;

	std::cout << std::string(80, '-') << std::endl;
	bill.signForm(form1);
	bill.signForm(form3);
	bill.signForm(form5);
	
	std::cout << std::string(80, '-') << std::endl;
	jackson.signForm(form1);
	jackson.signForm(form3);
	jackson.signForm(form5);

	std::cout << std::string(80, '-') << std::endl;
	emily.signForm(form3);
	emily.signForm(form5);
	
	std::cout << std::string(80, '-') << std::endl;
	frank.signForm(form5);
	std::cout << std::string(80, '-') << std::endl;
	bill.executeForm(form1);
	bill.executeForm(form2);
	bill.executeForm(form3);
	bill.executeForm(form4);
	bill.executeForm(form5);
	bill.executeForm(form6);
	std::cout << std::string(80, '-') << std::endl;
	jackson.executeForm(form1);
	jackson.executeForm(form3);
	jackson.executeForm(form5);
	std::cout << std::string(80, '-') << std::endl;
	emily.executeForm(form3);
	emily.executeForm(form5);
	std::cout << std::string(80, '-') << std::endl;
	frank.executeForm(form3);
	frank.executeForm(form5);
	std::cout << std::string(80, '-') << std::endl;
	caroline.executeForm(form5);
}