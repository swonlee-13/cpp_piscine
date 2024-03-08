#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *Brain;
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
