#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap & src);

		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void ninjaShoebox(ClapTrap &trap);
		void ninjaShoebox(FragTrap &trap);
		void ninjaShoebox(ScavTrap &trap);
		void ninjaShoebox(NinjaTrap &trap);

		NinjaTrap & operator=(NinjaTrap const & src);

		~NinjaTrap(void);

};

#endif
