#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Error : put 1 argument only." << std::endl;
        return (1);
        
    }
    Harl harl;
    std::string message = av[1];
    harl.complain(message);
    return (0);
}