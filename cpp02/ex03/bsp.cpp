#include "Point.hpp"

int	crossProduct(Point A, Point B, Point point) {
	Fixed pax = A.getX() - point.getX();
	Fixed pay = A.getY() - point.getY();
	Fixed pbx = B.getX() - point.getX();
	Fixed pby = B.getY() - point.getY();

	Fixed cross = pax * pby - pay * pbx;
	return (cross.getRawBits());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    int area1 = crossProduct(a, b, point);
	int area2 = crossProduct(b, c, point);
	int area3 = crossProduct(c, a, point);

	if ((area1 > 0 && area2 > 0 && area3 > 0) || (area1 < 0 && area2 < 0 && area3 < 0))
		return (true);
	else
		return (false);
}
