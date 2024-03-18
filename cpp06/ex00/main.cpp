#include "ScalarConverter.hpp"

int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
	std::string param = av[1];
    ScalarConverter::convert(param);

    return 0;
}
