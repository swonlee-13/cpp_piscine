#include "iter.hpp"
#include <iostream>


template <typename T>
void myprint(T &param) {
	std::cout << param << std::endl;
}

int main()
{
	int *arr = new int[10];
	for (std::size_t i = 0; i < 10 ; i++)
		arr[i] = i;
	iter<int>(arr, 10, myprint<int>);
	delete[] arr;
}