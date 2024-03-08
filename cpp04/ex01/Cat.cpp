#include "Cat.hpp"

/* OCCF */
Cat::Cat() : Animal("cat") {
	this->Brain = new class Brain();
	std::cout << "cat created 🐈." << std::endl;
}

Cat::Cat(const Cat &Copy) : Animal("cat") {
	*this = Copy;
}

Cat &Cat::operator=(const Cat &Copy) {
	if (this != &Copy) {
		std::cout << "cat created 🐈." << std::endl;
		this->_type = Copy._type;
	}
	return *this;
}

Cat::~Cat() {
	delete this->Brain;
	std::cout << "Cat destructor called 🐈." << std::endl;
}

/* Overloaded function */
void Cat::makeSound() const {
	std::cout << "Meow Meow ~~~~~~~~~🐈." << std::endl;
}
