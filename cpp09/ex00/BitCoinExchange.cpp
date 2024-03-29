#include "BitCoinExchange.hpp"
#include <iostream>

BitCoinExchange::BitCoinExchange() {}

BitCoinExchange::~BitCoinExchange() {}

std::pair<int, double> BitCoinExchange::parseData(std::string &line) const {
	std::stringstream ss(line);
	std::string tmp;

	int year, month, day, rawData;
	char empty;
	double value;
	std::string trash;
	std::string trash2;

	ss >> year >> empty >> month >> empty >> day >> trash >> value >> trash2;
	if (trash != "|" || !trash2.empty())
		throw std::invalid_argument("Error: bad input =>" + line);
	rawData = year * 10000 + month * 100 + day;

	if (value > 1000)
		throw std::invalid_argument("Error: Too large number.");
	if (value < 0)
		throw std::invalid_argument("Error: not a positive number.");

	if (rawData < _priceData.begin()->first  || month > 12)
	throw std::invalid_argument("Error: bad input => " + line);

	int monthtable[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (!(year % 400 != 0 && year % 100 == 0) && year % 4 == 0)
		++monthtable[1];
	if (day > monthtable[month - 1])
		throw std::invalid_argument("Error: bad input =>" + line);
	return (std::pair<int, double>(rawData, value));
}

void BitCoinExchange::initializeInputData(std::ifstream &raw) {
	std::string str;
	std::pair<int, double> line;

	//header skip
	std::getline(raw, str);
	if (str != "date | value")
		throw std::invalid_argument("Error: Wrong input header. => " + str);
	while (std::getline(raw, str)){
		try {
			if (str.empty())
				continue;
			if (isspace(str[0]))
				throw std::invalid_argument("Error: bad input => remove space.");
			line = parseData(str);			
			printLine(line);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void BitCoinExchange::initializePriceData(std::ifstream &raw) {
	std::stringstream ss;
	std::string str;

	int year, month, day, dateToInt;
	char empty;
	double value;

	//header skip
	std::getline(raw, str);
	while (std::getline(raw, str)){
		ss << str;
		ss >> year >> empty >> month >> empty >> day;
		dateToInt = year * 10000 + month * 100 + day;
		ss.ignore(1, ',');
		ss >> value;
		ss.str("");
		ss.clear();
		_priceData.insert(std::pair<int, double>(dateToInt, value));
	}
}

void BitCoinExchange::printLine(std::pair<int, double> &line) {
	int year, month, day;

	std::map<int, double>::iterator it;
	it = _priceData.upper_bound(line.first);
	it--;
	year = line.first / 10000;
	month = line.first % 1000 / 100;
	day = line.first % 100;

	std::cout <<  year << "-";
	if (month > 9)
		std::cout << month << "-";
	else
		std::cout << "0" << month << "-";
	if (day > 9)
		std::cout << day;
	else
		std::cout << "0" << day;
	std::cout << " => " << line.second << " = " << it->second * line.second << std::endl;
}
