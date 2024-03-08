#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed
{
    private:
		int	_fixedPointValue;
		static const int _bit = 8;
    public:
		Fixed();
		Fixed(const Fixed &Copy);
		Fixed &operator=(const Fixed &Copy);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif
