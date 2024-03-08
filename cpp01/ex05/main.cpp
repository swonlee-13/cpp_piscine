#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string level;

    while (true) {
        std::cout << "level : ";
        std::getline(std::cin, level);
        if (std::cin.eof())
            break;
        harl.complain(level);
    }
    std::cin.clear();
    return (0);
}