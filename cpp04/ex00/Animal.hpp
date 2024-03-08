#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;
	public:
	/* OCCF */
		Animal();
		Animal(const Animal &Copy);
		Animal &operator=(const Animal &Copy);
		virtual ~Animal();
	/* Additional Constructor */
		Animal(std::string type);
	/* Member function - Mandatory */
		virtual void makeSound() const;
	/* Getter, Setter */
		std::string getType() const;
	
};
#endif
