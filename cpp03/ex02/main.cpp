#include "FragTrap.hpp"

int main()
{
    std::cout << "-------------test0 : Conversion Constructor" << std::endl;
    FragTrap Me("babo");
    std::cout << "-------------test1 : Copy Constructor" << std::endl;
    FragTrap Clone(Me);
    std::cout << "-------------test2 : Value test" << std::endl;
    std::cout << Clone.getName() << std::endl;
    std::cout << Clone.getEnergyPoint() << std::endl;
    std::cout << "-------------test3 : Highfive test" << std::endl;
    Me.highFiveGuys();
    std::cout << "-------------test5 : Attack message test" << std::endl;
    Me.attack("babo");
    Clone.takeDamage(Me.getAttackDamage());

}
