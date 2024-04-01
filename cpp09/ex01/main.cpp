#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "invalid argment." << std::endl;
		return EXIT_FAILURE;
	}
	if (!RPN::isStrValid(av[1])) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	RPN Calc(av[1]);
	try {
	Calc.calculateRPN();
	Calc.printResult();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}