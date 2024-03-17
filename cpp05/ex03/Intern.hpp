#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
	private:
		Intern(const Intern &Copy);
		Intern &operator=(const Intern &Copy);
	public:
		Intern();
		~Intern();
		AForm * makeForm(const std::string &nameOfForm, const std::string &typeOfForm);
};
#endif
