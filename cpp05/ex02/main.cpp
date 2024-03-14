#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat bob("bob", 1);
		// Bureaucrat hi("hi", 151);
		Bureaucrat seongwol("seongwol", 3);
		AForm *Plant = new ShrubberyCreationForm("Tree");
		AForm *Robot = new RobotomyRequestForm("Robot");
		AForm *Coffee_man = new PresidentialPardonForm("Coffee-man");
		
		std::cout << "-------------Execute test----------" << std::endl;
		seongwol.signForm(*Plant);
		seongwol.signForm(*Robot);
		seongwol.signForm(*Coffee_man);
		std::cout << std::endl;
		seongwol.executeForm(*Plant);
		std::cout << std::endl;
		seongwol.executeForm(*Coffee_man);
		std::cout << std::endl;
		seongwol.executeForm(*Robot);
		std::cout << std::endl;
		delete Plant;
		delete Robot;
		delete Coffee_man;
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
