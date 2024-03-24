#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = Copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &Copy) {
    if (this != &Copy) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->setRawBits(Copy.getRawBits());
    }
    return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}
