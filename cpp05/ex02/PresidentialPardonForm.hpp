#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <ctime>
# include <cstdlib>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm &operator=(const PresidentialPardonForm &Copy);
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &Copy);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};
#endif
