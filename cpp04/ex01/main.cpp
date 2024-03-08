#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "-----------test1-----------" << std::endl;
	const Animal *animal[4];
	
	animal[0] = new Cat();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Dog();

	std::cout << std::endl << "-----------test2------------" << std::endl << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << "idx = " << i << " ";
		animal[i]->makeSound();
	}

	std::cout << std::endl << "-----------test3------------" << std::endl;

	for(int i = 0; i < 4; i++) {
		delete animal[i];
	}
	return 0;
}