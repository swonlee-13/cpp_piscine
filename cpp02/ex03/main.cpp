#include "Point.hpp"

int main( void )
{
	Point A(Fixed(10.1f), Fixed(0));
	Point B(Fixed(-10.1f), Fixed(0));
	Point C(Fixed(0), Fixed(10));
	Point P(Fixed(-10.1f), Fixed(0));

	bool res = bsp(A, B, C, P);
	if (res == true)
		std::cout << "This point is in the triangle." << std::endl;
	else
		std::cout << "This point is not in the triangle." << std::endl;
}
