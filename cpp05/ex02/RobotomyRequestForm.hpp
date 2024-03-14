#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <ctime>
# include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm &operator=(const RobotomyRequestForm &Copy);
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &Copy);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};
#endif
