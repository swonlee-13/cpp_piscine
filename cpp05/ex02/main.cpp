#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
	try {
		Bureaucrat bob("bob", 1);
		// Bureaucrat hi("hi", 151);
		Bureaucrat seongwol("seongwol", 3);
		ShrubberyCreationForm Plan("Tree");

		std::cout << "-------------Execute test----------" << std::endl;
		seongwol.signForm(Plan);
		seongwol.executeForm(Plan);
		std::cout << std::endl;
	
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
