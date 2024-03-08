#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource created." << std::endl;
	for (int i = 0; i < 4; i++)
		_skill[i] = NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &Copy) {
	if (this != &Copy) {
		std::cout << "Copy assignment operator called." << std::endl;
		for (int i = 0; i < 4; i++) {
			if (_skill[i] != NULL) { delete _skill[i]; }
			_skill[i] = Copy._skill[i];
		}
	}
	return *this;
}

MateriaSource::MateriaSource(const MateriaSource &Copy) {
	std::cout << "MateriaSource created." << std::endl;
	*this = Copy;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource deleted." << std::endl;
	for (int i = 0; i < 4; i++) {
		delete _skill[i];
	}
}

void MateriaSource::learnMateria(AMateria *param) {
	for (int i = 0; i < 4; i++) {
		if (_skill[i] == NULL) {
			_skill[i] = param;
			return ;
		}
	}
	std::cerr << "Skill slots are full." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_skill[i] != NULL && _skill[i]->getType() == type)
			return _skill[i]->clone();
	}
	std::cerr << "* There's no skill named " << type << ". *" << std::endl;
	return (0);
}