#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Character::Character() : _name("default") {
	for(int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(std::string name) : _name(name) {
	for(int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(const Character &Copy) {*this = Copy;}

Character &Character::operator=(const Character &Copy) {
	if (this != &Copy) {
		this->_name = Copy._name;
		for (int i = 0; i < 4; i++) {
			if (_slot[i] != NULL) { delete _slot[i];}
			_slot[i] = Copy._slot[i];
		}
	}
	return *this;
}

std::string const & Character::getName() const {return _name;}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_slot[i] != NULL)
			delete _slot[i];
	}
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_slot[i] == NULL) {
			_slot[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	delete _slot[idx];
	_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	_slot[idx]->use(target);
	delete _slot[idx];
	_slot[idx] = NULL;
}
