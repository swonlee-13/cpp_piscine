#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	/* OCCF */
		WrongCat();
		WrongCat(const WrongCat &Copy);
		WrongCat &operator=(const WrongCat &Copy);
		~WrongCat();
	/* overloaded function */
		void makeSound() const;
};
#endif
