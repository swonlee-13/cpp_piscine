#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class AMateria;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &Copy);
		Ice &operator=(const Ice &Copy);
		~Ice();
		void use(ICharacter& target);
		Ice* clone() const;
};
#endif
