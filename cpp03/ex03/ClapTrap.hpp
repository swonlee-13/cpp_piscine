#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        /* member variables */
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;

    public:
        /* OCCF */
        ClapTrap();
        ClapTrap(const ClapTrap &Copy);
        ClapTrap &operator=(const ClapTrap &Copy);
        ~ClapTrap();

        /* Additional Constructor */
        ClapTrap(const std::string &name);

        /* Getter, Setter */
        std::string getName(void) const;
        int getHitPoint(void) const;
        int getEnergyPoint(void) const;
        int getAttackDamage(void) const;
        void setName(std::string name);
        void setHitPoint(unsigned int hitPoint);
        void setEnergyPoint(unsigned int energyPoint);
        void setAttackDamage(unsigned int attackPoint);

        /* Member function - Mandatory */
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif