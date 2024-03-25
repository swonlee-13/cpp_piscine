#include "Span.hpp"
#include <iostream>
#include <string>

int main()
{
	Span A(11);
	A.addNumber(100);
	A.addNumber(10);
	A.addNumber(11);
	A.addNumber(12);
	A.addNumber(13);
	A.addNumber(13);
	A.addNumber(13);
	A.addNumber(13);
	A.addNumber(25);
	try {
		A.addNumber(1);
		A.addNumber(9);
		A.addNumber(13);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Span B(A);
	int data1 = B.longestSpan();
	int data2 = B.shortestSpan();

	std::cout << "longestSpan: " << data1 << std::endl;
	std::cout << "shortestSpan: " << data2 << std::endl;
}