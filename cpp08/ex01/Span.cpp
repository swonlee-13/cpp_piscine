#include "Span.hpp"

Span::Span() : _n(0), _vector(), _currentNumberOfData(0){}

Span::Span(unsigned int n) : _n(n), _vector(n), _currentNumberOfData(0) {}

Span::Span(const Span &Copy) {
	*this = Copy;
}

Span &Span::operator=(const Span &Copy) {
	if (this != &Copy) {
		_n = Copy._n;
		_vector = Copy._vector;
		_currentNumberOfData = Copy._currentNumberOfData;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int data) {
	if (_currentNumberOfData < _n) {
		_vector[_currentNumberOfData] = data;
		_currentNumberOfData++;
	}
	else
		throw std::invalid_argument("Error: Array is full.");
}

void Span::addNumber(iterator_t begin, iterator_t end) {
	try {
		for(iterator_t it = begin; it != end; it++)
			addNumber(*it);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

size_t Span::longestSpan() {
	size_t max = static_cast<size_t>(*(std::max_element(_vector.begin(), _vector.end())));
	size_t min = static_cast<size_t>(*(std::min_element(_vector.begin(), _vector.end())));
	return (max - min);
}

size_t Span::shortestSpan() {
	std::vector<int> copy;
	copy = _vector;
	std::sort(copy.begin(), copy.end());
	// for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
    // 	int element = *it;
	// 	std::cout << element << "@" << std::endl;
	// }	
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin(), Span::abs_diff);
	
	return (*std::min_element(copy.begin() + 1, copy.end()));
}

size_t Span::abs_diff(int a, int b){
	return (static_cast<size_t>(std::abs(a - b)));
}
