#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string type){
    this->type = type;
}

Weapon::Weapon(const Weapon& Weapon){
    this->type = Weapon.type;
}

Weapon::~Weapon(){

}

const std::string& Weapon::getType(void) const{
    return (type);
}

void    Weapon::setType(std::string type){
     this->type = type;
}
