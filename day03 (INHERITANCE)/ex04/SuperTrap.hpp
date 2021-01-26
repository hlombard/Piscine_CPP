#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

	public:
		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);

		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void printInfo(void);

		SuperTrap & operator=(SuperTrap const & src);

		~SuperTrap(void);

};

#endif
