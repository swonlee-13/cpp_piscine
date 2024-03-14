#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &Copy);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &Copy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};
#endif
