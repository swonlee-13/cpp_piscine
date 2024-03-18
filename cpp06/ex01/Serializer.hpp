#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &Copy);
		Serializer &operator=(const Serializer &Copy);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data * deSerialize(uintptr_t raw);
};
#endif
