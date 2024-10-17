#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try {
        Bureaucrat john("John", 2);
        Form taxForm("Tax Form", 3, 5);

        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat jane("Jane", 6);
        jane.signForm(taxForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}