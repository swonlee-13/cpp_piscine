#include "AMateria.hpp"

AMateria::AMateria() : _type("none") {}

AMateria::AMateria(std::string const &type) :_type(type) {}

AMateria::AMateria(const AMateria &Copy) {*this = Copy;}

AMateria &AMateria::operator=(const AMateria &Copy) {
	if (this != &Copy) {
		_type = Copy._type;
	}
	return *this;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cerr << "Wrong." << std::endl;
}
std::string const &AMateria::getType() const {return _type;}

AMateria::~AMateria() {}
