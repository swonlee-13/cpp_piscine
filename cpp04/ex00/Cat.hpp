#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
	/* OCCF */
		Cat();
		Cat(const Cat &Copy);
		Cat &operator=(const Cat &Copy);
		~Cat();
	/* overloaded function */
		void makeSound() const;
};
#endif
