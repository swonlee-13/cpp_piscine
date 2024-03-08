#include "WrongAnimal.hpp"

/* OCCF */
WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << "WrongAnimal created 🌎." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Copy) {
	std::cout << "WrongAnimal created 🌎." << std::endl;
	*this = Copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Copy) {
	if (this != &Copy) {
		std::cout << "WrongAnimal created 🌎." << std::endl;
		_type = Copy._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called." << std::endl;
}

/* Additional Constructor */
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal created 🌎" << std::endl;
}

/* Member function - Mandatory */
void WrongAnimal::makeSound() const {
	std::cout << "🌎 God hasn't defined the sound for this animal yet 🌎." << std::endl;
}

/* Getter, Setter */
std::string WrongAnimal::getType() const {
	return _type;
}
