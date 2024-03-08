#include "FragTrap.hpp"

/* OCCF */
FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    _name = "default";
    _hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &Copy) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = Copy;
}

FragTrap &FragTrap::operator=(const FragTrap &Copy) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &Copy) {
        _name = Copy._name;
        _hitPoint = Copy._hitPoint;
        _energyPoint = Copy._energyPoint;
        _attackDamage = Copy._attackDamage;;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

/* Additional constructor */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap conversion constructor called" << std::endl;
    _name = name;
    _hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}
/* Member functions - Mandatory */
void FragTrap::highFiveGuys() {
    if (_energyPoint > 0 && _hitPoint > 0) {
        std::cout << "hi~~~~~~~~~~~~guys~~~~~~~~~~" << std::endl;
        _energyPoint -= 1;
    } else if (_energyPoint <= 0) {
        std::cout << "FragTrap " << _name << " highfive : not enough energy." << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " has been defeated already." << std::endl;
    }
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoint <= 0) {
        std::cout << "FragTrap " << _name << " has been defeated already." << std::endl;
    } else if (_energyPoint > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of Damage!" << std::endl;
        _energyPoint -= 1;
    } else {
        std::cout << "FragTrap " << _name << " attack : not enough energy" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0) {
        std::cout << "FragTrap " << _name << " took " << amount << " damage." << std::endl;
		_hitPoint -= amount;
    if (_hitPoint <= 0)
        std::cout << "FragTrap " << _name << " has been defeated." << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " has been defeated already." << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0) {
        std::cout << "FragTrap " << _name << " healed itself for " << amount << " hitPoint" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    } else if (_energyPoint == 0) {
        std::cout << "FragTrap " << _name << " repair : not enough energy." << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " has been defeated already." << std::endl;
    }
}
