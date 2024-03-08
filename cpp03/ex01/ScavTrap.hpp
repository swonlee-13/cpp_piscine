#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        int _gateKeeperMode;
    public:
        /* OCCF */
        ScavTrap();
        ScavTrap(const ScavTrap &Copy);
        ScavTrap &operator=(const ScavTrap &Copy);
        ~ScavTrap();

        /* Additional Constructor */
        ScavTrap(std::string name);

        /* member function - Mandatory */
        void guardGate();

        /* Member function - Mandatory */
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        /* getter */
        int getGateKeeperMode(void) const;
};
