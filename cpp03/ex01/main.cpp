#include "ScavTrap.hpp"

int main()
{
    std::cout << "-------------test0 : Conversion Constructor" << std::endl;
    ScavTrap Me("babo");
    std::cout << "-------------test1 : Copy Constructor" << std::endl;
    ScavTrap Clone(Me);
    std::cout << "-------------test2 : Value test" << std::endl;
    std::cout << Clone.getName() << std::endl;
    std::cout << Clone.getEnergyPoint() << std::endl;
    std::cout << "-------------test3 : Guardgate test" << std::endl;
    Clone.guardGate();
    std::cout << Clone.getGateKeeperMode() << std::endl;
    std::cout << "-------------test4 : Guardgate2 test" << std::endl;
    Clone.guardGate();
    std::cout << Clone.getGateKeeperMode() << std::endl;
    std::cout << "-------------test5 : Attack message test" << std::endl;
    Me.attack("babo");
    Clone.takeDamage(Me.getAttackDamage());
}
