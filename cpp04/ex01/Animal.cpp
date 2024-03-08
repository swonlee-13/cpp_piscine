#include "Animal.hpp"

/* OCCF */
Animal::Animal() : _type("default") {
	std::cout << "Animal created 🌎." << std::endl;
}

Animal::Animal(const Animal &Copy) {
	std::cout << "Animal created 🌎." << std::endl;
	*this = Copy;
}

Animal &Animal::operator=(const Animal &Copy) {
	if (this != &Copy) {
		std::cout << "Animal created 🌎." << std::endl;
		_type = Copy._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called 🌎." << std::endl;
}

/* Additional Constructor */
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal created 🌎" << std::endl;
}

/* Member function - Mandatory */
void Animal::makeSound() const {
	std::cout << "🌎 God hasn't defined the sound for this animal yet 🌎." << std::endl;
}

/* Getter, Setter */
std::string Animal::getType() const {
	return (_type);
}
