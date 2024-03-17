#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("bob", 1);
		Bureaucrat seongwol("seongwol", 150);
		// Bureaucrat error("error", 151);

		seongwol.increment(3);
		seongwol.getGrade();
		seongwol.decrement(3);
		seongwol.getGrade();
		seongwol.increment(151);

		std::cout << "final grade for ";
		std::cout << seongwol << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bye" << std::endl;
	return 0;
}