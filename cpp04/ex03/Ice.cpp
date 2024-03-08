#include "Ice.hpp"

Ice::Ice() :AMateria("ice") {}

Ice::Ice(const Ice &Copy) : AMateria(Copy._type) {
	*this = Copy;
}

Ice &Ice::operator=(const Ice &Copy) {
	if (this != &Copy) {
		this->_type = Copy._type;
	}
	return *this;
}

Ice::~Ice() {}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}

Ice *Ice::clone() const {
	return (new Ice(*this));
}
