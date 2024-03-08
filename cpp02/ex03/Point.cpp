#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}

Point::Point(const Point &Copy) : _x(Copy.getX()), _y(Copy.getY()) {}

/* Undifined Behavior*/
Point &Point::operator=(const Point &Copy) {
    if (this == &Copy) return *this;
    else return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const {return this->_x;}

Fixed Point::getY(void) const {return this->_y;}
