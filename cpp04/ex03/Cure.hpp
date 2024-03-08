#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &Copy);
		Cure &operator=(const Cure &Copy);
		~Cure();
		void use(ICharacter& target);
		Cure* clone() const;
};
#endif
