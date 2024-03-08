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
		Fixed(const int param);
		Fixed(const float param);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const param);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &param);
#endif
