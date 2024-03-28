#include "BitCoinExchange.hpp"
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string file = av[1];
	if (file.substr(file.length() - 4, file.length()) != ".txt") {
		std::cerr << "Error: invalid filename extension.";
		return 1;
	}
	std::ifstream rawdata("./data.csv");
	std::ifstream input(file);
	if (rawdata.fail() || input.fail()) {
		std::cerr << "Error: could not open file." <<  std::endl;
		return 1;
	}
	BitCoinExchange Data;
	Data.initializePriceData(rawdata);
	Data.initializeInputData(input);
}
