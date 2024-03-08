#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
	/* OCCF */
		Dog();
		Dog(const Dog &Copy);
		Dog &operator=(const Dog &Copy);
		~Dog();
	/* Overloaded function */
		void makeSound() const;
};
#endif
