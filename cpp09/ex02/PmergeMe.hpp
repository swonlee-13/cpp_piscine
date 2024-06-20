#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iomanip>
# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <stack>
# include <deque>
# include <algorithm>
# include <utility>
# include <sys/time.h>
# include <unistd.h>

typedef std::vector<unsigned int>::iterator vec_it;
typedef std::deque<unsigned int>::iterator deq_it;
typedef std::vector<std::pair<unsigned int, unsigned int> >::iterator pvec_it;
typedef std::deque<std::pair<unsigned int, unsigned int> >::iterator pdeq_it;

class PmergeMe
{
private:
	static size_t jacobsthal[53];
	
	std::vector<unsigned int> _vectorToSort;
	std::vector<unsigned int> _vectorSorted;
	std::deque<unsigned int> _dequeToSort;
	std::deque<unsigned int> _dequeSorted;
	double _timeVectorStart, _timeVectorEnd, _timeDequeStart, _timeDequeEnd;
	PmergeMe();

protected:
	/* #region InternalMethods */
	void arrangePair(std::vector<std::pair<unsigned int, unsigned int> > &pairs);
	void arrangePair(std::deque<std::pair<unsigned int, unsigned int> > &pairs);
	pvec_it findPairByLarge(std::vector<std::pair<unsigned int, unsigned int> > &pairs, unsigned int largeNum);
	pdeq_it findPairByLarge(std::deque<std::pair<unsigned int, unsigned int> > &pairs, unsigned int largeNum);
	void makeSmallVector(std::vector<unsigned int> &sortedLarge, std::vector<unsigned int> &small, std::vector<std::pair<unsigned int, unsigned int> > &pairs, bool flag, unsigned int remainingNumber);
	void makeSmallVector(std::deque<unsigned int> &sortedLarge, std::deque<unsigned int> &small, std::deque<std::pair<unsigned int, unsigned int> > &pairs, bool flag, unsigned int remainingNumber);
	void printTimeWithVector();
	void printTimeWithDeque();
	void printVector(const char * message, std::vector<unsigned int> &param);
	void timeStamp(double &value);
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
	void recursionStart(std::vector<unsigned int> &param);
	void recursionStart(std::deque<unsigned int> &param);
	void printResult();
	
	/* #endregion */
	
};

#endif