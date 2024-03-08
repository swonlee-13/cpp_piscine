#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Materia " << _type << " created." << std::endl;
}

Cure::Cure(const Cure &Copy) : AMateria(Copy._type) {
	std::cout << "Materia " << _type << " created." << std::endl;
	*this = Copy;
}

Cure &Cure::operator=(const Cure &Copy) {
	if (this != &Copy) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->_type = Copy._type;
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Materia " << _type << " deleted." << std::endl;
}

void Cure::use(ICharacter &target) {
	std::cout <<"* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure *Cure::clone() const {
	return (new Cure(*this));
}
