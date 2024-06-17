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
									3002399751580331u };

PmergeMe::PmergeMe(int ac, char **av) : swapCount(0)
{
	for (std::size_t i = 0; i < ac; i++)
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
	this->swapCount = Copy.swapCount;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &Copy)
{
	this->_vectorToSort = Copy._vectorToSort;
	this->_vectorSorted = Copy._vectorSorted;
	this->_listToSort = Copy._listToSort;
	this->_listSorted = Copy._listSorted;
	this->swapCount =Copy.swapCount;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::arrangePair(std::vector<std::pair<unsigned int, unsigned int>> &pairs)
{
	std::vector<std::pair<unsigned int, unsigned int>>::iterator it;
	for (it = pairs.begin(); it != pairs.end(); it++) {
		if ((*it).first < (*it).second) {
			unsigned int temp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = temp;
		}
	}
}
//pair 의 first 가 큰 수로 갔음 헷갈리기 ㄴㄴ ;;
void PmergeMe::mergeInsertionSort(std::vector<unsigned int> &param)
{
	std::vector<std::pair<unsigned int, unsigned int>> pairs;
	std::vector<unsigned int> large;
	std::pair<unsigned int, unsigned int> numPair;
	bool			oddFlag = (param.size() % 2 == 0) ? false : true;
	unsigned int	remainingNumber;

	if (param.size() == 1) {
		_vectorSorted.push_back(param.front());
		return ;
	}
	for (std::size_t i = 0; i < param.size(); i += 2)
		pairs.push_back(std::make_pair(param[i], param[i + 1]));
	if (oddFlag)
		remainingNumber = param.back();
	arrangePair(pairs);
	for (std::size_t i = 0; i < pairs.size(); i++)
		large.push_back(pairs[i].first);
	mergeInsertionSort(large);
	for (std::size_t i = 1; jacobsthal[i] > _vectorSorted.size(); i++) {
		vec_it start = getIterator(_vectorSorted, jacobsthal[i - 1]);
		vec_it end = (jacobsthal[i] > _vectorSorted.size()) ? getIterator(_vectorSorted, _vectorSorted.size()) : getIterator(_vectorSorted, jacobsthal[i]);

		for (vec_it it = end; it != start; it--) {
			pvec_it pit = std::lower_bound(pairs.begin(), pairs.end(), *it);
			unsigned int numToInsert = pit->second;
			vec_it itToInsert= std::lower_bound(_vectorSorted.begin(), _vectorSorted.end(), numToInsert);
			
		}
	}
}

vec_it PmergeMe::getIterator(std::vector<unsigned int> &param, std::size_t jacobNum) {
	vec_it ret = param.begin();
	for (int i = 0; i < jacobNum; i++) {
		++ret;
	}
	return ret;
}
