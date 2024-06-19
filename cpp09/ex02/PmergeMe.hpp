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
	void makeSmallVector(std::vector<unsigned int> &large, std::vector<unsigned int> &small, std::vector<std::pair<unsigned int, unsigned int> > &pairs, bool flag, unsigned int remainingNumber);
	void printBefore();
	void printAfter();
	void printTimeWithVector();
	void printTimeWithList();

	/* #endregion */

	//for evaluation
	void printVector(const char * message, std::vector<unsigned int> &param);

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
	
};

inline bool operator<(const std::pair<const unsigned int, const unsigned int> &lft, const std::pair<const unsigned int, const unsigned int> &rgt)
{
	return (lft.first < rgt.first);
}

#endif