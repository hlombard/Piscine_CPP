#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main(void) {

	// Init
	std::cout << "Initialize 1" << std::endl;
	ClapTrap *claptrap = new ClapTrap("claptrap");
	std::cout << "Initialize 2" << std::endl;
	FragTrap *fragtrap = new FragTrap("fragtrap");
	std::cout << "Initialize 3" << std::endl;
	ScavTrap *scavtrap = new ScavTrap("scavtrap");
	std::cout << std::endl << std::endl;

	// Special funcs
	std::cout << "FragTrap special func called" << std::endl;
	fragtrap->vaulthunter_dot_exe("someone");
	std::cout << std::endl;
	std::cout << "ScavTrap special func called" << std::endl;
	scavtrap->challengeNewcomer("someone else");
	std::cout << std::endl << std::endl;

	// Common funcs
	std::cout << "Common funcs" << std::endl;
	fragtrap->meleeAttack("toto");
	scavtrap->meleeAttack("tutu");
	fragtrap->rangedAttack("toto");
	scavtrap->rangedAttack("tutu");
	std::cout << std::endl << std::endl;

	// Destroy
	std::cout << "Destroying vars" << std::endl;
	delete fragtrap;
	delete scavtrap;
	delete claptrap;

	return (0);
}
