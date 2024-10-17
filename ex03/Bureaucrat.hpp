# ifndef BUREAUCRAT_HPP
#  define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm; 
class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:

		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm& form);

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
	};

	std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat);

#endif