#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Base *generate(void) {
	std::srand(time(NULL));
	int num = std::rand();
	if (num % 3 == 0)	return new A();
	else if (num % 3 == 1)	return new B();
	else	return new C(); 
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p: C" << std::endl;
	else
		std::cout << "This is not a pointer between A, B and C" << std::endl;
}

void identify(Base &p) {
	try {
		A &temp = dynamic_cast<A&>(p);
		(void)temp;
		std::cout << "p: A" << std::endl;
		return ;
	} catch (std::bad_cast &e) {
		try {
			B &temp = dynamic_cast<B&>(p);
			(void)temp;
			std::cout << "p: B" << std::endl;
			return ;
		} catch (std::bad_cast &e) {
			try {
			C &temp = dynamic_cast<C&>(p);
			(void)temp;
			std::cout << "p: C" << std::endl;
			return ;
			} catch (std::exception &e) {
				std::cout << "This is not a referenct of A, B and C" << std::endl;
			}
		}	
	}
}

int main()
{
	Base *var1 = generate();
	std::cout << "test1: run pointer" << std::endl;
	identify(var1);
	std::cout << std::endl;
	std::cout << "test2: run reference" << std::endl;
	identify(*var1);
	std::cout << std::endl;
	std::cout << "test end. Thank you." << std::endl;
}