#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &Copy);
		Bureaucrat &operator=(const Bureaucrat &Copy);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;		
		void increment();
		void decrement();

		void signForm(AForm &param);
		void executeForm(AForm const & form);

		class GradeTooLowException : public std::exception {
			public : 
				const char *what()const throw();
		};

		class GradeTooHighException : public std::exception {
			public :
				const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &param);
#endif
