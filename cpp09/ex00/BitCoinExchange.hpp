#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <sstream>
# include <map>
# include <iostream>
# include <exception>
# include <fstream>
class BitCoinExchange
{
	private:
		std::map<int, double> _priceData;

		BitCoinExchange(const BitCoinExchange &Copy);
		BitCoinExchange &operator=(const BitCoinExchange &Copy);
		std::pair<int, double> parseData(std::string &date) const;

	public:
		BitCoinExchange();
		~BitCoinExchange();

		void handleInputData(std::ifstream &raw);
		void initializePriceData(std::ifstream &raw);

		void printLine(std::pair<int, double> &line);
};
#endif
