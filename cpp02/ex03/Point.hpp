#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    private:
		Fixed const _x;
		Fixed const _y;
		/* OCCF - not used */
	public:
		/* OCCF */
		Point();
		Point	&operator=(const Point &Copy);
		Point(const Point &Copy);
		~Point();

		/* Other Constructors */
		Point(Fixed const x, Fixed const y);

		/* member functions */
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};
int	crossProduct(Point A, Point B, Point point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif