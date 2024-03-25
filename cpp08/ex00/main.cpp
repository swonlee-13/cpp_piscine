#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> A;

	A.push_back(0);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	std::vector<int>::iterator it = easyfind(A, 10);
	std::cout << *it << std::endl;
}