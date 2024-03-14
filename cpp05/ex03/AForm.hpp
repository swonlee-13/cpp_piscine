#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp" 

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		AForm &operator=(const AForm &Copy);
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &Copy);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGrageToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &param);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception {
			public: 
				const char *what()const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what()const throw();
		};

		class NotSignedYetException : public std::exception {
			public:
				const char *what()const throw();
		};

		class GradeReverseOrderException : public std::exception {
			public:
				const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &param);
#endif
