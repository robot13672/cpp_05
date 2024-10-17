#include "Bureaucrat.hpp"

int main() 
{
    Bureaucrat bur("John", 150);
    std::cout << bur;
    try
    {
        bur.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat Illia("Illia", 10);
    for (int i = 0; i < 11; i++)
    {
        try
        {
            Illia.decrementGrade();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    Bureaucrat Ivan = Illia;
    std::cout << Ivan;
    Bureaucrat Peter(bur);
}