#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "invalid argment." << std::endl;
		return EXIT_FAILURE;
	}
	PmergeMe A(ac, av);
	if (A.validCheck(ac, av) == false) {
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
    A.mergeInsertionSort();
	A.printResult();
}