#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> A(2);
	A[0] = 1;
	A[1] = 2;
	for (int i = 0; i < 2; i++) {
		std::cout << A[i] << std::endl;
	}
	std::cout << "size: " << A.size() << std::endl;
}