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

	//std::cout << __FILE__ << ":" << __LINE__ << std::endl;

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
		if ((*it).first < (*it).second) {
			unsigned int temp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = temp;
		}
	}
}

void PmergeMe::makeSmallVector(std::vector<unsigned int> &large, std::vector<unsigned int> &small, std::vector<std::pair<unsigned int, unsigned int> > &pairs)
{
	for (vec_it it = large.begin(); it != large.end(); it++) {
		unsigned int smallNum = findPairByLarge(pairs, *it)->second;
		small.push_back(smallNum);
	}
}
//pair 의 first 가 큰 수로 갔음 헷갈리기 ㄴㄴ ;;
void PmergeMe::mergeInsertionStart(std::vector<unsigned int> &param)
{
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<unsigned int> large, small;
	vec_it itToInsert, start, end;
	bool			oddFlag = (param.size() % 2 == 0) ? false : true;
	unsigned int	remainingNumber = oddFlag ? param.back() : 0;
	unsigned int numToInsert;

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
	mergeInsertionStart(large);
	makeSmallVector(large, small, pairs);
	std::cout << "end merge | current large length == "<< large.size() << std::endl;
	for (std::size_t i = 0; i == 0 || jacobsthal[i - 1] < small.size(); i++) {
		std::cout << "i = " << i << std::endl;
		if (i == 0) {
			std::cout << "just insert" << std::endl;
			_vectorSorted.insert(_vectorSorted.begin(), small[0]);
			printVector(_vectorSorted);
			continue;
		}
		start = getIterator(small, jacobsthal[i - 1]);
		end = getIterator(small, jacobsthal[i]);

		std::cout << "jacob[i - 1] = " << jacobsthal[i - 1] << std::endl;
		std::cout << "jacob[i] = " << jacobsthal[i] << std::endl;
		
		if (oddFlag && end == small.end() - 1) {
			std::cout << "odd num handling" << std::endl;
			itToInsert = std::lower_bound(_vectorSorted.begin(), _vectorSorted.end(), remainingNumber);
			_vectorSorted.insert(itToInsert, remainingNumber);
			printVector(_vectorSorted);
			oddFlag = false;
		}
		for (vec_it it = end; it != start; it--) {
			pvec_it pit = findPairByLarge(pairs, *it);
			if (pit == pairs.end())
				continue;
			std::cout << "normal insert" << std::endl;
			unsigned int numToInsert = pit->second;
			std::cout << "numToInsert = " << numToInsert << std::endl;
			itToInsert = std::lower_bound(_vectorSorted.begin(), _vectorSorted.end(), numToInsert);
			_vectorSorted.insert(itToInsert, numToInsert);
			pairs.erase(pit);
			printVector(_vectorSorted);
		}
	}
	std::cout << "end recursion" << std::endl << std::endl;
}

void PmergeMe::mergeInsertionSort() {
	mergeInsertionStart(_vectorToSort);
	std::cout << "Sort finished" << std::endl;
}

vec_it PmergeMe::getIterator(std::vector<unsigned int> &param, std::size_t jacobNum)
{
	vec_it ret = param.begin();
	for (std::size_t i = 0; i < jacobNum && ret != param.end(); i++)
		++ret;
	if (ret == param.end())
		return ret - 1;
	else
		return ret;
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

const std::vector<unsigned int> &PmergeMe::getVectorToSort() const {return _vectorToSort;}

const std::list<unsigned int> &PmergeMe::getListToSort() const {return _listToSort;}

void PmergeMe::printResult()
{
	printBefore();
	printAfter();
	printTimeWithVector();
	printTimeWithList();
}

void	PmergeMe::printBefore()
{
	std::cout << "Before:   ";
	for (std::size_t i = 0; i < _vectorToSort.size(); i++) {
		std::cout << _vectorToSort[i];
		if (i != _vectorToSort.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}


void	PmergeMe::printAfter()
{
	std::cout << "After:    ";
	for (std::size_t i = 0; i < _vectorSorted.size(); i++) {
		std::cout << _vectorSorted[i];
		if (i != _vectorSorted.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTimeWithVector()
{
	std::cout << "time here" << std::endl;
}

void PmergeMe::printTimeWithList()
{
	std::cout << "time here" << std::endl;
}
