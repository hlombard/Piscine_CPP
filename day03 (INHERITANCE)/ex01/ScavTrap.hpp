#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ScavTrap {

	private:
		unsigned int _hitPoints;
		unsigned int _maxHitPoints;
		unsigned int _energyPoints;
		unsigned int _maxEnergyPoints;
		unsigned int _level;
		std::string _name;

		unsigned int _meleeAttackDamage;
		unsigned int _rangedAttackDamage;
		unsigned int _armorDamageReduction;

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);

		ScavTrap & operator=(ScavTrap const & src);

		~ScavTrap(void);
};

#endif
