#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstdlib>
# include <cstring>
# include <exception>
# include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _length;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &Copy);
		Array &operator=(const Array &Copy);
		~Array();

		T &operator[](int idx);
		unsigned int size() const;
};

# include "Array.tpp"

#endif
