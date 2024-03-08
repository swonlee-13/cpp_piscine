#include "ClapTrap.hpp"

int main()
{
    ClapTrap Me("seongwol");
    ClapTrap You("youngjin");

    Me.setAttackDamage(0);
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    Me.attack(You.getName());
    You.takeDamage(Me.getAttackDamage());
    Me.attack(You.getName());
    You.takeDamage(Me.getAttackDamage());
    Me.beRepaired(5);
    You.beRepaired(5);
    std::cout << "h.p -- youngjin -> " << You.getHitPoint() << std::endl;
}
