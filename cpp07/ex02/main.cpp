#include "Array.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "----------normal test----------" << std::endl;
		Array<int> A(2);
		A[0] = 1;
		A[1] = 2;
		for (int i = 0; i < 2; i++) {
			std::cout << A[i] << std::endl;
		}
		std::cout << "size: " << A.size() << std::endl;
	}
	{
		Array<int> A(2);
		std::cout << "----------test -1 index with catch------------" << std::endl;
		try {
			std::cout << A[-1] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "----------test -1 index without catch (Abort occurs)----------" << std::endl;
		std::cout << A[3] << std::endl;
	}
}