#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_skill[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &Copy);
		MateriaSource &operator=(const MateriaSource &Copy);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
#endif
