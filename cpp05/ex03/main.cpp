#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern Intern1;
		AForm * form1 = Intern1.makeForm("Presidential Pardon", "hi");
		Bureaucrat me("seongwol", 3);
		me.signForm(*form1);
		me.executeForm(*form1);
	}
	catch (char const * e) {
		std::cerr << e << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bye" << std::endl;
	return 0;
}
