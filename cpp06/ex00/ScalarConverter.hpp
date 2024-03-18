#ifndef SCALERCONVERTER_HPP
# define SCALERCONVERTER_HPP
# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &Copy);
		ScalarConverter &operator=(const ScalarConverter &Copy);
		static bool isValidInput(const std::string &param);
	public:
		~ScalarConverter();
		static void convert(const std::string &param);
};
#endif
