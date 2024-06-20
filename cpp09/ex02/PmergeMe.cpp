#include "PmergeMe.hpp"

size_t PmergeMe::jacobsthal[53] = {	1u,
									3u,
									5u,
									11u,
									21u,
									43u,
									85u,
									171u,
									341u,
									683u,
									1365u,
									2731u,
									5461u,
									10923u,
									21845u,
									43691u,
									87381u,
									174763u,
									349525u,
									699051u,
									1398101u,
									2796203u,
									5592405u,
									11184811u,
									22369621u,
									44739243u,
									89478485u,
									178956971u,
									357913941u,
									715827883u,
									1431655765u,
									2863311531u,
									5726623061u,
									11453246123u,
									22906492245u,
									45812984491u,
									91625968981u,
									183251937963u,
									366503875925u,
									733007751851u,
									1466015503701u,
									2932031007403u,
									5864062014805u,
									11728124029611u,
									23456248059221u,
									46912496118443u,
									93824992236885u,
									187649984473771u,
									375299968947541u,
									750599937895083u,
									1501199875790165u,
									3002399751580331u
};

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		_vectorToSort.push_back(std::atoi(av[i]));
		_listToSort.push_back(std::atoi(av[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &Copy)
{
	this->_vectorToSort = Copy._vectorToSort;
	this->_vectorSorted = Copy._vectorSorted;
	this->_listToSort = Copy._listToSort;
	this->_listSorted = Copy._listSorted;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &Copy)
{
	if (this != &Copy) {
		this->_vectorToSort = Copy._vectorToSort;
		this->_vectorSorted = Copy._vectorSorted;
		this->_listToSort = Copy._listToSort;
		this->_listSorted = Copy._listSorted;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::arrangePair(std::vector<std::pair<unsigned int, unsigned int> > &pairs)
{
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first < it->second) {
			unsigned int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void PmergeMe::makeSmallVector(std::vector<unsigned int> &sortedLarge, std::vector<unsigned int> &small, std::vector<std::pair<unsigned int, unsigned int> > &pairs, bool flag, unsigned int remainingNumber)
{
	for (vec_it it = sortedLarge.begin(); it != sortedLarge.end(); it++) {
		pvec_it pit = findPairByLarge(pairs, *it);
		unsigned int smallNum = pit->second;
		small.push_back(smallNum);
		pairs.erase(pit);
	}
	if (flag)
		small.push_back(remainingNumber);
}

pvec_it PmergeMe::findPairByLarge(std::vector<std::pair<unsigned int, unsigned int> > &pairs, unsigned int largeNum)
{
	for (pvec_it pit =  pairs.begin(); pit != pairs.end(); pit++) {
		if (pit->first == largeNum) {
			return pit;
		}
	}
	return pairs.end();
}

void PmergeMe::recursionStart(std::vector<unsigned int> &param)
{
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<unsigned int> large, small;
	bool			oddFlag = (param.size() % 2 == 0) ? false : true;
	unsigned int	remainingNumber = oddFlag ? param.back() : 0;

	if (param.size() < 2) {
		_vectorSorted.push_back(param[0]);
		return ;
	}
	for (std::size_t i = 0; i < param.size(); i += 2) {
		if (!(oddFlag && i == param.size() - 1))
			pairs.push_back(std::make_pair(param[i], param[i + 1]));
	}
	arrangePair(pairs);
	for (std::size_t i = 0; i < pairs.size(); i++)
		large.push_back(pairs[i].first);
	recursionStart(large);
	makeSmallVector(_vectorSorted, small, pairs, oddFlag, remainingNumber);
	unsigned int loopCount = 0;
	for (std::size_t i = 0; i == 0 || jacobsthal[i - 1] < small.size(); i++) {
		if (i == 0) {
			_vectorSorted.insert(_vectorSorted.begin(), small[0]);
			continue;
		}
		std::size_t start = jacobsthal[i - 1] - 1;
		std::size_t end = (jacobsthal[i] > small.size()) ? small.size() - 1 : jacobsthal[i] - 1;
		for (std::size_t j = end; j != start; j--) {
			vec_it itEnd = (j == end && small.size() % 2 == 1) ? _vectorSorted.end() : _vectorSorted.begin() + loopCount + j;
			vec_it itToInsert = std::lower_bound(_vectorSorted.begin(), itEnd, small[j]);
			_vectorSorted.insert(itToInsert, small[j]);
			loopCount++;
		}
	}
}
void PmergeMe::timeStamp(double &value)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	value = time.tv_sec * 1000 + time.tv_usec / 1000;
}


void PmergeMe::mergeInsertionSort()
{
	timeStamp(_timeVectorStart);
	recursionStart(_vectorToSort);
	timeStamp(_timeVectorEnd);
	timeStamp(_timeListStart);
	recursionStart(_vectorToSort); // overloading needed
	timeStamp(_timeListEnd);
}

void PmergeMe::printVector(const char *message, std::vector<unsigned int> &param) {
	std::cout << message;
	for (std::size_t i = 0; i < param.size() ; i++) {
		std::cout << param[i];
		if (i != _vectorToSort.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printResult()
{
	printVector("Before:   ", _vectorToSort);
	printVector("After:    ", _vectorSorted);
	printTimeWithVector();
	printTimeWithList();
}

void PmergeMe::printTimeWithVector()
{
	std::cout << "time here" << std::endl;
}

void PmergeMe::printTimeWithList()
{
	std::cout << "time here" << std::endl;
}
