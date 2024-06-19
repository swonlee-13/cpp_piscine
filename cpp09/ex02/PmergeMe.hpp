#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include <utility>

typedef std::vector<unsigned int>::iterator vec_it;
typedef std::vector<std::pair<unsigned int, unsigned int> >::iterator pvec_it;

class PmergeMe
{
private:
	std::vector<unsigned int> _vectorToSort;
	std::vector<unsigned int> _vectorSorted;
	std::list<unsigned int> _listToSort;
	std::list<unsigned int> _listSorted;
	static size_t jacobsthal[];
	PmergeMe();

protected:
	/* #region InternalMethods */
	void arrangePair(std::vector<std::pair<unsigned int, unsigned int> > &pairs);
	vec_it getIterator(std::vector<unsigned int> &param, std::size_t jacobNum); // overloading needed
	pvec_it findPairByLarge(std::vector<std::pair<unsigned int, unsigned int> > &pairs, unsigned int largeNum);
	void makeSmallVector(std::vector<unsigned int> &large, std::vector<unsigned int> &small, std::vector<std::pair<unsigned int, unsigned int> > &pairs);
	void printBefore();
	void printAfter();
	void printTimeWithVector();
	void printTimeWithList();

	/* #endregion */


public:
	/* #region OCCF */
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &Copy);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &Copy);
	
	/* #endregion */

	/* #region  AvailableMethods */
	void mergeInsertionSort();
	void mergeInsertionStart(std::vector<unsigned int> &param);
	void printResult();
	
	/* #endregion */

	const std::vector<unsigned int> &getVectorToSort() const;
	const std::list<unsigned int> &getListToSort() const;

	void printVector(std::vector<unsigned int> &param) {
		std::cout << "--------------printing | ";
		for (std::size_t i = 0; i < param.size() ; i++) {
			std::cout << param[i] << " ";
		}
		std::cout << std::endl;
	}
};

inline bool operator<(const std::pair<const unsigned int, const unsigned int> &lft, const std::pair<const unsigned int, const unsigned int> &rgt)
{
	return (lft.first < rgt.first);
}

#endif