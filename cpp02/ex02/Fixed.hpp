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

		// 비교연산자
		bool operator<(const Fixed &Param) const;
		bool operator>(const Fixed &Param) const;
		bool operator>=(const Fixed &Param) const;
		bool operator<=(const Fixed &Param) const;
		bool operator==(const Fixed &Param) const;
		bool operator!=(const Fixed &Param) const;

		// + - * / 연산자
		Fixed operator+(const Fixed &Param);
		Fixed operator-(const Fixed &Param);
		Fixed operator*(const Fixed &Param);
		Fixed operator/(const Fixed &Param);

		//증감연산자
		Fixed operator++();
		Fixed operator--(int num);
		Fixed operator++(int num);
		Fixed operator--();

		static Fixed &min(Fixed &lft, Fixed &rgt);
		static const Fixed &min(const Fixed &lft, const Fixed &rgt);
		static Fixed &max(Fixed &lft, Fixed &rgt);
		static const Fixed &max(const Fixed &lft, const Fixed &rgt);
};

// 출력 연산자
std::ostream &operator<<(std::ostream &out, const Fixed &param);
#endif
