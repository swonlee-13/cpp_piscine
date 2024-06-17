#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include <utility>

typedef std::vector<unsigned int>::iterator								vec_it;
typedef std::vector<std::pair<unsigned int, unsigned int>>::iterator	pvec_it;


class PmergeMe
{
	private:
		std::vector<unsigned int> _vectorToSort;
		std::vector<unsigned int> _vectorSorted;
		std::list<unsigned int> _listToSort;
		std::list<unsigned int> _listSorted;
		int swapCount;
		static size_t jacobsthal[];
		PmergeMe();
	protected:
		void		arrangePair(std::vector<std::pair<unsigned int, unsigned int>> &pairs);

	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &Copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &Copy);
		void		mergeInsertionSort(std::vector<unsigned int> &param);
		void		printResult();
		vec_it		getIterator(std::vector<unsigned int> &param, std::size_t jacobNum); //overloading needed
};

inline bool operator<(std::pair<unsigned int, unsigned int> lft, std::pair<unsigned int, unsigned int> rgt) {
	return (lft.first < rgt.first);
}

#endif