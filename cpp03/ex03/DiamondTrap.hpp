#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

    public:
        /* OCCF */
        DiamondTrap();
        DiamondTrap(const DiamondTrap &Copy);
        DiamondTrap &operator=(const DiamondTrap &Copy);
        ~DiamondTrap();

        /* Additional Constructor */
        DiamondTrap(const std::string &name);

        /* Member function - Mandatory */
        using ScavTrap::attack;
		void whoAmI();
		void displayStatus();
};
#endif
