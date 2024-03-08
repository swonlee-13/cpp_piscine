#include "Zombie.hpp"

int main()
{
    Zombie *Zombies;

    int num = 10;
    Zombies = zombieHorde(num, "zombie");
    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < num ; i++)
        Zombies[i].announce();
    for (int i = 0; i < num; i++)
        Zombies[i].~Zombie();
}