#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>
# include <iostream>

template <typename T, typename F>
void iter(T *array, std::size_t length, F f) {
	for (std::size_t i = 0; i < length; i++)
		f(array[i]);
}
#endif
