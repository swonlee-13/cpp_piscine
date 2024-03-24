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

Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = param << 8;  
}

Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = static_cast<int>(roundf(param * (1 << _bit)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const param) {
    _fixedPointValue = param;
}

float   Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _bit);
}

int     Fixed::toInt(void) const {
    return _fixedPointValue >> 8;
}

std::ostream &operator<<(std::ostream &out, const Fixed &param) {

    out << param.toFloat();
    return out;
}