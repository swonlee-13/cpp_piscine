#include "WrongCat.hpp"

/* OCCF */
WrongCat::WrongCat() : WrongAnimal("cat") {
	std::cout << "cat created 🐈." << std::endl;
}

WrongCat::WrongCat(const WrongCat &Copy) : WrongAnimal("cat") {
	*this = Copy;
}

WrongCat &WrongCat::operator=(const WrongCat &Copy) {
	if (this != &Copy) {
		std::cout << "cat created 🐈." << std::endl;
		this->_type = Copy._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called 🐈." << std::endl;
}

/* Overloaded function */
void WrongCat::makeSound() const {
	std::cout << "Meow Meow ~~~~~~~~~🐈." << std::endl;
}