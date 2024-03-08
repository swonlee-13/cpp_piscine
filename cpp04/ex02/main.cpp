#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// std::cout << "-----------test1------------" << std::endl;
	// 	const Animal *animal[4];

	// 	animal[0] = new Cat();
	// 	animal[1] = new Dog();
	// 	animal[2] = new Cat();
	// 	animal[3] = new Dog();

	// 	for(int i = 0; i < 4; i++) {
	// 		delete animal[i];
	// 	}
	// 	return 0;
	std::cout << "-----------test2-----------" << std::endl;
	const Animal *animal[4];
	
	animal[0] = new Cat();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Dog();

	for (int i = 0; i < 4; i++) {
		animal[i]->makeSound();
		delete animal[i];
	}
}