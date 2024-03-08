#include "DiamondTrap.hpp"


/* OCCF */
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), _name("default") {
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &Copy) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
	ClapTrap::_name = Copy.ClapTrap::_name;
	_name = Copy._name;
	_hitPoint = Copy._hitPoint;
	_energyPoint = Copy._energyPoint;
	_attackDamage = Copy._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &Copy) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &Copy) {
		ClapTrap::_name = Copy.ClapTrap::_name;
		_name = Copy._name;
		_hitPoint = Copy.DiamondTrap::_hitPoint;
		_energyPoint = Copy.DiamondTrap::_energyPoint;
		_attackDamage = Copy.DiamondTrap::_attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/* Additional constructor */
DiamondTrap::DiamondTrap(const std::string &name) : _name(name) {
	std::cout << "DiamondTrap conversion constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	DiamondTrap::_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
}

void DiamondTrap::whoAmI() {
	std::cout << "---------------------------Who am i?------------------------------" << std::endl << std::endl;
	std::cout << "Type : DiamondTrap"<< std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl << std::endl;
}

void DiamondTrap::displayStatus() {
	std::cout << "-------------------------Display Status----------------------------" << std::endl << std::endl;
	std::cout << "Hit point : " << _hitPoint << std::endl;
	std::cout << "Energy point : " << _energyPoint << std::endl;
	std::cout << "Attack damage : " << _attackDamage << std::endl << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
}