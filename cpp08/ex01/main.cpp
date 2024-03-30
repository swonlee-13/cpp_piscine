#include "Span.hpp"
#include <iostream>
#include <string>

int main()
{
	{
		Span A(12);
		try {
		A.addNumber(100);
		A.addNumber(10);
		A.addNumber(11);
		A.addNumber(12);
		A.addNumber(13);
		A.addNumber(13);
		A.addNumber(13);
		A.addNumber(13);
		A.addNumber(25);
		A.addNumber(1);
		A.addNumber(9);
		A.addNumber(13);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		Span B(A);
		int dataA1 = A.longestSpan();
		int dataA2 = A.shortestSpan();

		int data1 = B.longestSpan();
		int data2 = B.shortestSpan();
		std::cout << "AlongestSpan: " << dataA1 << std::endl;
		std::cout << "AshortestSpan: " << dataA2 << std::endl << std::endl;

		std::cout << "BlongestSpan: " << data1 << std::endl;
		std::cout << "BshortestSpan: " << data2 << std::endl;
	}
	{
		std::cout << std::endl <<  "====================" << std::endl << "test for multi add" << std::endl << std::endl;

		Span A(10);
		std::vector<int> cmp(100);
		for(int i = 0; i < 100; i++) {
			cmp[i] = (i);
		}
		std::cout << "cmp: " << *cmp.begin() << "," << *(cmp.end() - 1) << "," << cmp.size() << std::endl;
		A.addNumber(cmp.begin(), cmp.end());
		size_t hi1 = A.longestSpan();
		size_t hi2 = A.shortestSpan();

		std::cout << "longest span: " << hi1 << std::endl;
		std::cout << "shortest span: " << hi2 << std::endl;
	}
}