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
	public:
		~ScalarConverter();
		static void convert(std::string param);
};
#endif
