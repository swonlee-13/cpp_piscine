#include "AMateria.hpp"

AMateria::AMateria() : _type("none") {
	std::cout << "Ameteria created." << std::endl;
}

AMateria::AMateria(std::string const &type) :_type(type) {
	std::cout << "Amateria created." << std::endl;
}

AMateria::AMateria(const AMateria &Copy) {
	std::cout << "Amateria created." << std::endl;
	*this = Copy;
}

AMateria &AMateria::operator=(const AMateria &Copy) {
	if (this != &Copy) {
		std::cout << "Copy assignment operator called." << std::endl;
		_type = Copy._type;
	}
	return *this;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cerr << "Wrong." << std::endl;
}
std::string const &AMateria::getType() const {return _type;}

AMateria::~AMateria() {
	std::cout << "Amateria deleted." << std::endl;
}
