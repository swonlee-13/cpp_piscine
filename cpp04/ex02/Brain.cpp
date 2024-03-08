#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created." << std::endl;
}

Brain::Brain(const Brain &Copy) {
	std::cout << "Copy assignment constructor called." << std::endl;
	*this = Copy;
}

Brain &Brain::operator=(const Brain &Copy) {
	if (this != &Copy) {
		for (int i = 0 ; i < 100 ; i++)
			this->idea[i] = Copy.idea[i].c_str();
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain deleted." << std::endl;
}
