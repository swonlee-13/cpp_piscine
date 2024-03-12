#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp" 

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		Form &operator=(const Form &Copy);
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &Copy);
		~Form();

		std::string getName () const;
		bool getIsSigned() const;
		int getGrageToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &param);

		class GradeTooLowException : public std::exception {
			public : 
				const char *what()const throw();
		};

		class GradeTooHighException : public std::exception {
			public :
				const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &param);
#endif
