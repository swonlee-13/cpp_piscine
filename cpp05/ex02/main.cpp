#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	try {
		Bureaucrat bob("bob", 1);
		// Bureaucrat hi("hi", 151);
		Bureaucrat seongwol("seongwol", 3);
		AForm *Plant = new RobotomyRequestForm("Tree");

		std::cout << "-------------Execute test----------" << std::endl;
		seongwol.signForm(*Plant);
		seongwol.executeForm(*Plant);
		std::cout << std::endl;
		delete Plant;
	}
	catch (char const * e) {
		std::cerr << e << std::endl;
	}
	catch (std::ios_base::failure &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bye" << std::endl;
	return 0;
}
