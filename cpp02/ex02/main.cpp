#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f) / Fixed(2));
	float c = 5.05f / 2;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "additional divide test : " << d << std::endl;
	std::cout << "compare to float : " << c << std::endl;

	std::cout << "---------- ++ test -----------" << std::endl;
	Fixed test(10.1231231f);
	Fixed res = test++;
	std::cout << res << std::endl;
	Fixed test2(10.1231231f);
	Fixed res2 = ++test2;
	std::cout << res2 << std::endl;
	
	return 0;
}
