#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &Copy) {(void)Copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Copy) {(void)Copy; return *this;}

ScalarConverter::~ScalarConverter() {}

bool isPrint(char c) { return (c >= 33 && c <= 126);}

void ScalarConverter::convert(std::string& literal) {
    char c;
    int i;
    float f;
    double d;
    bool charImpossible = false;
    bool intImpossible = false;
    bool floatImpossible = false;
    bool doubleImpossible = false;
	
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        charImpossible = true;
        intImpossible = true;
        f = literal == "-inff" ? -std::numeric_limits<float>::infinity() :
            literal == "+inff" ? std::numeric_limits<float>::infinity() : 
            std::numeric_limits<float>::quiet_NaN();
		d = static_cast<double>(f);
    } else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        charImpossible = true;
        intImpossible = true;
        d = literal == "-inf" ? -std::numeric_limits<double>::infinity() :
            literal == "+inf" ? std::numeric_limits<double>::infinity() :
            std::numeric_limits<double>::quiet_NaN();
		f = static_cast<float>(d);
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        if (std::isprint(literal[0])) c = literal[0];
		else {
			charImpossible = true;
			c = '\0';
		}
		if (c != '\0') {
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
    } else {
        try {
            i = static_cast<int>(std::stoi(literal));
			if (std::isprint(i)) {
				c = static_cast<char>(i);
			} else {charImpossible = true;}
        } catch (const std::invalid_argument& e) {
			charImpossible = true;
            intImpossible = true;
        } catch (const std::out_of_range& e) {
			charImpossible = true;
            intImpossible = true;
        }

        try {
            f = std::stof(literal);
        } catch (const std::invalid_argument& e) {
            floatImpossible = true;
        } catch (const std::out_of_range& e) {
            floatImpossible = true;
        }

        try {
            d = std::stod(literal);
        } catch (const std::invalid_argument& e) {
            doubleImpossible = true;
        } catch (const std::out_of_range& e) {
            doubleImpossible = true;
        }

        if (!intImpossible && !floatImpossible && !doubleImpossible) {
            charImpossible = std::isprint(static_cast<char>(i)) == 0;
        }
    }

    std::cout << "char: ";
    if (charImpossible) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "'" << c << "'" << std::endl;
    }

    std::cout << "int: ";
    if (intImpossible) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i << std::endl;
    }

    std::cout << "float: ";
    if (floatImpossible) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << f;
        if (f - i == 0) {
            std::cout << ".0";
        }
		std::cout << "f" << std::endl;
    }

    std::cout << "double: ";
    if (doubleImpossible) {
        std::cout << "impossible" << std::endl;
    } else {
		std::cout << d;
        if (d - i == 0) {
            std::cout << ".0";
        }
		std::cout << std::endl;
    }
}