#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound! j->makeSound();
    meta->makeSound();
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;
	delete meta;
	return 0;
}

 /* test : no virtual keyword at : makeSound */
// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound! j->makeSound();
//     meta->makeSound();
// 	i->makeSound();
// 	delete i;
// 	delete meta;
// 	return 0;
// }
