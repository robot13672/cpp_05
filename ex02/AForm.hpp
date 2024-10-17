#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;
	public:
		AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();
	public:
		AForm(const std::string name, int gradeSign, int gradeExec);
		virtual void	execute(Bureaucrat const& b) const = 0;
		const std::string getName() const;
		int	getGradeSign() const;
		int	getGradeExec() const;
		bool getSigned() const;
		void beSigned(Bureaucrat& b);
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream& stream, AForm& form);

#endif