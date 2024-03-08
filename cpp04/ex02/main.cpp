#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "--------------test : normal test-----------" << std::endl;
	const Animal *animal[4];
	
	animal[0] = new Cat();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Dog();

	for (int i = 0; i < 4; i++) {
		animal[i]->makeSound();
		delete animal[i];
	}

	// std::cout << "-----------test : doesn't work----------" << std::endl;
	// const Animal *animal[4];
	
	// animal[0] = new Cat();
	// animal[1] = new Animal();
	// animal[2] = new Cat();
	// animal[3] = new Animal();

	// for (int i = 0; i < 4; i++) {
	// 	animal[i]->makeSound();
	// 	delete animal[i];
	// }
}