#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ClapTrap {

	protected:
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		std::string name;
		unsigned int meleeAttackDamage;
		unsigned int rangedAttackDamage;
		unsigned int armorDamageReduction;

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void);

		ClapTrap & operator=(ClapTrap const & src);

		~ClapTrap(void);
};

#endif
