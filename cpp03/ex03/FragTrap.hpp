#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        /* OCCF */
        FragTrap();
        FragTrap(const FragTrap &Copy);
        FragTrap &operator=(const FragTrap &Copy);
        ~FragTrap();

        /* Additional Constructor */
        FragTrap(const std::string &name);

        /* member function - Mandatory */
        void highFiveGuys(void);

        /* Member function - Mandatory */
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif
