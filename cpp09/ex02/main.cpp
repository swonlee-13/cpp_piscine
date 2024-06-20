#include <iostream>
#include "PmergeMe.hpp"



int main(int ac, char **av)
{
	PmergeMe A(ac, av);
	if (A.validCheck(ac, av) == false) {
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
    A.mergeInsertionSort();
	A.printResult();
}