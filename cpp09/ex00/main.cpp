#include "BitCoinExchange.hpp"
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::string file = av[1];
	std::string extention = file.substr(file.length() - 4, file.length());
	if (extention != ".txt" && extention != ".csv") {
		std::cerr << "Error: invalid filename extension.";
		return EXIT_FAILURE;
	}
	std::ifstream rawdata("./data.csv");
	std::ifstream input(file);
	if (rawdata.fail() || input.fail()) {
		std::cerr << "Error: could not open file." <<  std::endl;
		return EXIT_FAILURE;
	}
	BitCoinExchange Data;
	Data.initializePriceData(rawdata);
	Data.handleInputData(input);
}
