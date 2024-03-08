#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
	/* OCCF */
		WrongAnimal();
		WrongAnimal(const WrongAnimal &Copy);
		WrongAnimal &operator=(const WrongAnimal &Copy);
		virtual ~WrongAnimal();
	/* Additional Constructor */
		WrongAnimal(std::string type);
	/* Member function - Mandatory */
		void makeSound() const;
	/* Getter, Setter */
		std::string getType() const;
	
};
#endif
