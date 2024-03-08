#include "Dog.hpp"

/* OCCF */
Dog::Dog() : Animal("Dog") {
	this->Brain = new class Brain();
	std::cout << "Dog created 🐶." << std::endl;
}

Dog::Dog(const Dog &Copy) : Animal("Dog") {	
	*this = Copy;
}

Dog &Dog::operator=(const Dog &Copy)
{
	if (this != &Copy) {
		std::cout << "Dog created 🐶." << std::endl;
		_type = Copy._type;
	}
	return *this;
}

Dog::~Dog() {
	delete this->Brain;
	std::cout << "Dog destructor called." << std::endl;
}

/* Overloaded function */
void Dog::makeSound() const{
	std::cout << "Bark! Bark! 🐶." << std::endl;
}