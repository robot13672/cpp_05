#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("NoTarget") 
{
    std::cout << "CONSTRUCTOR WITHOUT PARAMETERS CALLED" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target) 
{
    std::cout << "COPPY CONSTRUCTOR CALLED" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "COPPY ASSIGNMENT CONSTRUCTOR CALLED" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);  
        this->target = copy.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ 
    std::cout << "DESTRUCTOR CALLED" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{ 
    std::cout << "CONSTRUCTOR WITH PARAMETERS CALLED" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
    if (b.getGrade() >= getGradeExec() && getSigned())
    {
        std::string	filename;
        filename = target + "_shrubbery.txt";
        std::ofstream output(filename.c_str(), std::ios::out);
        if (output.is_open())
        {
            output << "     ccee88oo\n"
                << "  C8O8O8Q8PoOb o8oo\n"
                << " dOB69QO8PdUOpugoO9bD\n"
                << "CgggbU8OU qOp qOdoUOdcb\n"
                << "    6OuU  /p u gcoUodpP\n"
                << "      \\\\//  /douUP\n"
                << "        \\\\////\n"
                << "         |||/\\\n"
                << "         |||\\/\n"
                << "         |||||\n"
                << "   .....//||||\\...." << std::endl;
            output.close();
            std::cout << b.getName() << " executes " << getName() << " on " << target << std::endl;
        }
    }
    else
    {
        if (!getSigned())
            std::cout << "This form '" << getName() << "' is not signed!" << std::endl;
        else
            throw AForm::GradeTooLowException();
    }
}