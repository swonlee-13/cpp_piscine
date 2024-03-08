#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
    : _name(name) ,_Weapon(NULL) {}

HumanB::~HumanB(){

}

void    HumanB::setWeapon(Weapon & Weapon){
    _Weapon = &Weapon;
}

void    HumanB::attack(void){
    if (_Weapon != NULL)
        std::cout << _name << " attacks with their " << _Weapon->getType() << "." << std::endl;
    else
        std::cout << _name << " attacks with his own hand." << std::endl;
}