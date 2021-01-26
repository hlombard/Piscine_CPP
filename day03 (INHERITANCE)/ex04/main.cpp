#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {

	SuperTrap super("SuperTrap");
	std::cout << std::endl;
	super.printInfo();

	super.rangedAttack("someone");
	super.meleeAttack("someone");
	std::cout << std::endl;

	super.vaulthunter_dot_exe("target");
	std::cout << std::endl;

	ClapTrap eric("eric");
	FragTrap frag("frag");
	ScavTrap scav("scav");
	NinjaTrap ninja("ninja");
	super.ninjaShoebox(eric);
	super.ninjaShoebox(frag);
	super.ninjaShoebox(scav);
	super.ninjaShoebox(ninja);
	std::cout << std::endl;

	return (0);
}
