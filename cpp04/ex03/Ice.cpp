#include "Ice.hpp"

Ice::Ice() :AMateria("ice") {
	std::cout << "Materia " << _type << " created." << std::endl;
}

Ice::Ice(const Ice &Copy) : AMateria(Copy._type) {
	std::cout << "Materia " << _type << " created." << std::endl;
	*this = Copy;
}

Ice &Ice::operator=(const Ice &Copy) {
	if (this != &Copy) {
		std::cout << "Copy assignment operator called." << std::endl;
		this->_type = Copy._type;
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Materia " << _type << " deleted." << std::endl;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}

Ice *Ice::clone() const {
	return (new Ice(*this));
}
