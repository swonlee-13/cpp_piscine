#include <iostream>
#include <string>
#include <stack>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "invalid argment." << std::endl;
		return EXIT_FAILURE;
	}
	std::stack<int> table;
	std::stack<double> calculator;
	
}