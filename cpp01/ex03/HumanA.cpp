#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, Weapon &X)
    : _Weapon(X) , _name(name){}

HumanA::~HumanA(){

}

void    HumanA::attack(void){
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
