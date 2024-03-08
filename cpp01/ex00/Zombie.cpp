#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    _name = name;
	std::cout << _name << ": created..........arrrrr" << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << ": dead........." << std::endl;
}

void    Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
