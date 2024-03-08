#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	private:
		std::string idea[100];
	public:
	/* OCCF */
		Brain();
		Brain(const Brain &Copy);
		Brain &operator=(const Brain &Copy);
		~Brain();
};
#endif
