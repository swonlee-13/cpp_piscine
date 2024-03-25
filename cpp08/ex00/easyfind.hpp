#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>

template <typename T>
typename T::iterator easyfind(T &array, int find) {
	return (std::find(array.begin(), array.end(), find));
}
#endif