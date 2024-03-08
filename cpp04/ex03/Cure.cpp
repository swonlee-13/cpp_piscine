#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &Copy) : AMateria(Copy._type) {
	*this = Copy;
}

Cure &Cure::operator=(const Cure &Copy) {
	if (this != &Copy) {
		this->_type = Copy._type;
	}
	return *this;
}

Cure::~Cure() {}

void Cure::use(ICharacter &target) {
	std::cout <<"* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure *Cure::clone() const {
	return (new Cure(*this));
}
