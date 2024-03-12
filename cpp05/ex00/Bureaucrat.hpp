#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		Bureaucrat &operator=(const Bureaucrat &Copy);
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &Copy);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;		
		void increment();
		void decrement();

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
