#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &Copy) {(void)Copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Copy) {(void)Copy; return *this;}

ScalarConverter::~ScalarConverter() {}

bool isPrint(char c) { return (c >= 33 && c <= 126);}

void printChar(std::string &param) {
	char c = param[0];
	std::cout << "char: ";
	if (isPrint(c) == true)	std::cout << "'" << c << "'" << std::endl;
	else std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) <<  std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(std::string param) {
	std::cout << "Input = " << param << std::endl;
	if (param.)
	else if (param.length() == 1 && isPrint(param[0]))
		printChar(param);
}