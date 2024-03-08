#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = Copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &Copy) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Copy)
		this->setRawBits(Copy.getRawBits()); 
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

bool Fixed::operator<(const Fixed &Param) const {
    return (this->getRawBits() < Param.getRawBits());
}

bool Fixed::operator>(const Fixed &Param) const {
    return (this->getRawBits() > Param.getRawBits());
}

bool Fixed::operator>=(const Fixed &Param) const {
    return (!(this->getRawBits() < Param.getRawBits()));
}

bool Fixed::operator<=(const Fixed &Param) const {
    return (!(this->getRawBits() > Param.getRawBits()));
}

bool Fixed::operator==(const Fixed &Param) const {
    return (this->_fixedPointValue == Param.getRawBits());
}

bool Fixed::operator!=(const Fixed &Param) const {
    return (!(this->_fixedPointValue == Param.getRawBits()));
}

Fixed Fixed::operator+(const Fixed &Param) {
    this->_fixedPointValue += Param.getRawBits();
    return *this;
}

Fixed Fixed::operator-(const Fixed &Param) {
    this->_fixedPointValue -= Param.getRawBits();
    return *this;
}

Fixed Fixed::operator*(const Fixed &Param) {
    this->_fixedPointValue = this->_fixedPointValue * Param.getRawBits() >> _bit;
    return *this;
}

Fixed Fixed::operator/(const Fixed &Param) {
    this->_fixedPointValue = (this->_fixedPointValue << _bit) / (Param.getRawBits());
    return *this;
}

Fixed Fixed::operator++() {
    this->_fixedPointValue += 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    this->_fixedPointValue += 1;
    return temp;
}

Fixed Fixed::operator--() {
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &lft, Fixed &rgt) {
    return ((lft < rgt) ? lft : rgt);
}

const Fixed& Fixed::min(const Fixed &lft, const Fixed &rgt) {
    return ((lft < rgt) ? lft : rgt);
}

Fixed& Fixed::max(Fixed &lft, Fixed &rgt) {
    return ((lft > rgt) ? lft : rgt);
}

const Fixed& Fixed::max(const Fixed &lft, const Fixed &rgt) {
    return ((lft > rgt) ? lft : rgt);
}
