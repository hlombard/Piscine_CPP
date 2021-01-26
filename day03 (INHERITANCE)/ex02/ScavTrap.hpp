#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void challengeNewcomer(std::string const & target);

		ScavTrap & operator=(ScavTrap const & src);

		~ScavTrap(void);
};

#endif
