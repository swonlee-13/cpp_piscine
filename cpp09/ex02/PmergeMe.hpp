#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stack>
#include <list>


class PmergeMe
{
	private:
		std::vector<unsigned int> _vectorToSort;
		std::vector<unsigned int> _vectorSorted;
		std::list<unsigned int> _listToSort;
		std::list<unsigned int> _listSorted;
		PmergeMe();
	protected:
		void	merge();
		void	insertion();
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &Copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &Copy);

		void	mergeInsertionSort(std::vector<int> &param);
		void	mergeInsertionSort(std::list<int> &param);
		void	printResult();
};
#endif