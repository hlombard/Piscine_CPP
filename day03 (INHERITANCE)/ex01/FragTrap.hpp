#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class FragTrap {

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

		void _speAttack0(std::string const & target) const;
		void _speAttack1(std::string const & target) const;
		void _speAttack2(std::string const & target) const;
		void _speAttack3(std::string const & target) const;
		void _speAttack4(std::string const & target) const;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);

		FragTrap & operator=(FragTrap const & src);

		~FragTrap(void);
};

#endif
