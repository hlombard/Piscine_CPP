#include "NinjaTrap.hpp"

int main(void) {

	std::cout << "Initialize 1" << std::endl;
	ClapTrap claptrap("claptrap");
	std::cout << std::endl;

	std::cout << "Initialize 2" << std::endl;
	FragTrap fragtrap("fragtrap");
	std::cout << std::endl;

	std::cout << "Initialize 3" << std::endl;
	ScavTrap scavtrap("scavtrap");
	std::cout << std::endl;

	std::cout << "Initialize 4" << std::endl;
	NinjaTrap ninjatrap;
	std::cout << std::endl << std::endl;

	ninjatrap.ninjaShoebox(claptrap);
	ninjatrap.ninjaShoebox(fragtrap);
	ninjatrap.ninjaShoebox(scavtrap);
	ninjatrap.ninjaShoebox(ninjatrap);
	std::cout << std::endl << std::endl;

	return (0);
}
