#include "ScavTrap.hpp"

/* OCCF */
ScavTrap::ScavTrap() : ClapTrap(), _gateKeeperMode(0) {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &Copy) : ClapTrap(Copy), _gateKeeperMode(Copy.getGateKeeperMode()) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &Copy) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &Copy) {
        _name = Copy.getName();
        _hitPoint = Copy.getHitPoint();
        _energyPoint = Copy.getEnergyPoint();
        _attackDamage = Copy.getAttackDamage();
		_gateKeeperMode = Copy.getGateKeeperMode();
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

/* Additional constructor */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(0) {
    std::cout << "ScavTrap conversion constructor called" << std::endl;
	_energyPoint = 50;
	_attackDamage = 20;
}

void ScavTrap::guardGate() {
	if (_energyPoint > 0 && _hitPoint > 0) {
	    if (_gateKeeperMode == 0) {
	        std::cout << "ScavTrap guard gate activated" << std::endl;
	        _gateKeeperMode = 1;
			_hitPoint += 100;
			_attackDamage -= 10;
	    } else if (_gateKeeperMode == 1) {
	        std::cout << "ScavTrap " << _name << " is already on gate keeper mode" << std::endl;
	    }
	} else if (_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name << " is already defeated." << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " has not enough energy" << std::endl;
	}
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoint <= 0) {
        std::cout << "ScavTrap " << _name << " has been defeated already." << std::endl;
        return ;
    }
    if (_energyPoint > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of Damage!" << std::endl;
        _energyPoint -= 1;
    } else {
        std::cout << "ScavTrap " << _name << " has not enough energy" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0) {
        std::cout << "ScavTrap " << _name << " took " << amount << " damage." << std::endl;
		_hitPoint -= amount;
    if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " has been defeated." << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " has been defeated already." << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0) {
        std::cout << "ScavTrap " << _name << " healed itself for " << amount << " hitPoint" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    } else if (_energyPoint == 0) {
        std::cout << "ScavTrap " << _name << " repair : not enough energy." << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " has been defeated already." << std::endl;
    }
}

/* getter */
int ScavTrap::getGateKeeperMode(void) const {
	return _gateKeeperMode;
}
