#include "Span.hpp"

Span::Span() : _n(0), _array(NULL), _numberOfDatas(0) {}

Span::Span(unsigned int n) : _n(n), _array(new int[n]), _numberOfDatas(0) {}

Span::Span(const Span &Copy) : _n(Copy._n), _numberOfDatas(Copy._numberOfDatas) {
	_array = new int[_n];
	std::copy(Copy._array, Copy._array + _n, _array);
}

Span &Span::operator=(const Span &Copy) {
	if (this != &Copy) {
		_n = Copy._n;
		_numberOfDatas = Copy._numberOfDatas;
		delete[] _array;
		_array = new int[_n];
		std::copy(Copy._array, Copy._array + _n, _array);
	}
	return *this;
}

Span::~Span() {
	delete[] _array;
}

void Span::addNumber(int data) {
	if (_n == 0 || _numberOfDatas == _n)
		throw std::out_of_range("Not enough space.");
	_array[_numberOfDatas] = data;
	++_numberOfDatas;
}

int Span::longestSpan() {
	if (_numberOfDatas == 0 || _numberOfDatas == 1)
		throw std::range_error("Not enough elements.");
	int max = *std::max_element(_array, _array + _numberOfDatas - 1);
	int min = *std::min_element(_array, _array + _numberOfDatas - 1);
	return (max - min);
}
int Span::shortestSpan() {
	if (_numberOfDatas == 0 || _numberOfDatas == 1)
		throw std::range_error("Not enough elements.");
	int *copy = new int[_n];
	copy = std::copy(_array, _array + _n, copy);
	std::sort(copy, copy + _numberOfDatas - 1);
	int res = copy[1] = copy[0];
	for (unsigned int i = 0; i < _numberOfDatas - 1; i++)
		if (copy[i + 1] - copy[i] < res)
			res = copy[i + 1] - copy[1];
	return res;
}
