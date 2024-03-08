#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        /* OCCF */
        FragTrap();
        FragTrap(const FragTrap &Copy);
        FragTrap &operator=(const FragTrap &Copy);
        ~FragTrap();

        /* Additional Constructor */
        FragTrap(std::string name);

        /* member function - Mandatory */
        void highFiveGuys(void);

        /* Member function - Mandatory */
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif
