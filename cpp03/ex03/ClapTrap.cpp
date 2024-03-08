#include "ClapTrap.hpp"

/* OCCF */
ClapTrap::ClapTrap() : _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap ::ClapTrap(const ClapTrap &Copy) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = Copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &Copy) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &Copy) {
    	_name = Copy._name;
    	_hitPoint = Copy._hitPoint;
    	_energyPoint = Copy._energyPoint;
    	_attackDamage = Copy._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

/* Additional Constructor */
ClapTrap::ClapTrap(const std::string &name) {
        std::cout << "ClapTrap Conversion constructor called" << std::endl;
        _name = name;
        _hitPoint = 10;
        _energyPoint = 10;
        _attackDamage = 0;
    }

/* Getter, Setter */
std::string ClapTrap::getName(void) const {return _name;}

int ClapTrap::getHitPoint(void) const {return _hitPoint;}

int ClapTrap::getEnergyPoint(void) const {return _energyPoint;}

int ClapTrap::getAttackDamage(void) const {return _attackDamage;}

void ClapTrap::setName(std::string name) {_name = name;}

void ClapTrap::setHitPoint(unsigned int hitPoint) {_hitPoint = hitPoint;}

void ClapTrap::setEnergyPoint(unsigned int energyPoint) {_energyPoint = energyPoint;}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {_attackDamage = attackDamage;}

/* Member function - Mandatory */
void ClapTrap::attack(const std::string &target) {
    if (_hitPoint <= 0) {
        std::cout << "ClapTrap " << _name << " is already defeated." << std::endl;
    }
    if (_energyPoint > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of Damage!" << std::endl;
        _energyPoint -= 1;
    } else {
        std::cout << "ClapTrap " << _name << " attack : not enough energy" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0) {
    std::cout << "ClapTrap " << _name << " took " << amount << " damage." << std::endl;
    _hitPoint -= amount;
    if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " has been defeated." << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has been defeated already." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0) {
        std::cout << "ClapTrap " << _name << " healed itself for " << amount << " hitPoint" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    } else if (_energyPoint == 0) {
        std::cout << "ClapTrap " << _name << " repair : not enough energy." << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has been defeated already." << std::endl;
    }
}
