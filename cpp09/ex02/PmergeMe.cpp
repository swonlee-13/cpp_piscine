#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
	for (std::size_t i = 0; i < ac; i++) {
		_vectorToSort.push_back(std::atoi(av[i]));
		_listToSort.push_back(std::atoi(av[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &Copy) {
	this->_vectorToSort = Copy._vectorToSort;
	this->_vectorSorted = Copy._vectorSorted;
	this->_listToSort = Copy._listToSort;
	this->_listSorted = Copy._listSorted;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &Copy) {
	this->_vectorToSort = Copy._vectorToSort;
	this->_vectorSorted = Copy._vectorSorted;
	this->_listToSort = Copy._listToSort;
	this->_listSorted = Copy._listSorted;
}

PmergeMe::~PmergeMe() {}

