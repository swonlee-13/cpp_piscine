#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_slot[4];
		std::string _name;
	public:
		Character();
		Character(std::string name);
		Character(const Character &Copy);
		Character &operator=(const Character &Copy);
		~Character();
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif
