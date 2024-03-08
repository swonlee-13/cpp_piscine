#include "Zombie.hpp"

int main()
{
    Zombie stack1("stack1");
    Zombie stack2("stack2");
    Zombie stack3("stack3");
    Zombie *heap1 = newZombie("heap1");
    Zombie *heap2 = newZombie("heap2");
    Zombie *heap3 = newZombie("heap3");
    randomChump("random1");
    randomChump("random2");
    randomChump("random3");
    heap1->~Zombie();
    heap2->~Zombie();
    heap3->~Zombie();
}