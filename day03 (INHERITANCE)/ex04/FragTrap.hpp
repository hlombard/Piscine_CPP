#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap {

	private:
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
		void vaulthunter_dot_exe(std::string const & target);

		FragTrap & operator=(FragTrap const & src);

		~FragTrap(void);
};

#endif
