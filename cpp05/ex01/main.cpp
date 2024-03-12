#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("bob", 1);
		// Bureaucrat hi("hi", 151);
		Bureaucrat seongwol("seongwol", 150);
		Form Plan("War machine plan", 100, 100);

		std::cout << "-------------signForm test(Wrong)----------" << std::endl;
		seongwol.signForm(Plan);
		std::cout << std::endl;
		std::cout << "-------------Form << test before sign.----------" << std::endl;
		std::cout << Plan << std::endl << std::endl;

		std::cout << "-------------signForm test(normal)----------" << std::endl;
		bob.signForm(Plan);
		std::cout << std::endl;

		std::cout << "-------------Form << test after sign.----------" << std::endl;
		std::cout << Plan << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bye" << std::endl;
	return 0;
}
