#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
    AMateria* tmp;

	std::cout << std::endl << "original test." << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

	std::cout << "test1 : try to create wrong skill" << std::endl << std::endl; 
	tmp = src->createMateria("Thunder");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);


	std::cout << "test2 : index test - after use skill [0], try to add new one to see whether 0 index occupied or not" << std::endl << std::endl;
	tmp = src->createMateria("ice");
    me->equip(tmp);
	me->use(0, *bob);

	std::cout << "test3 : full inventory test." << std::endl << std::endl;
	tmp = src->createMateria("ice");
    me->equip(tmp);
	tmp = src->createMateria("ice");
    me->equip(tmp);
	tmp = src->createMateria("ice");
    me->equip(tmp);
	tmp = src->createMateria("ice");
    me->equip(tmp);
	std::cout << "original test : use skill 1" << std::endl << std::endl;
    me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}