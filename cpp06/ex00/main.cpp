#include "ScalarConverter.hpp"

int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
	std::string param = av[1];
    try {
        ScalarConverter::convert(param);
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
