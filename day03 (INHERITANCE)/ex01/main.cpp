#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main(void) {

	FragTrap def;
	FragTrap toto("toto");

	//Attack normale, doit prendre en compte là réduction de dégâts
	// et impossible de dépasser 0 de points de vie ou d'envoyer des dégats négatifs
	std::cout << std::endl;
	toto.rangedAttack("default");
	def.takeDamage(20);
	toto.meleeAttack("default");
	def.takeDamage(-5);
	for (int i = 0; i < 8; i++) {
		def.takeDamage(20);
	}
	std::cout << std::endl << std::endl;


	//Healing impossible de dépasser maxHp et valeurs négatives;
	for (int i = 0; i < 22; i++) {
		def.beRepaired(5);
	}
	def.beRepaired(-500);
	def.beRepaired(500);
	std::cout << std::endl;

	// special attacks randoms
	toto.vaulthunter_dot_exe("default");
	def.takeDamage(104);
	toto.vaulthunter_dot_exe("default");
	def.takeDamage(120);
	def.takeDamage(-3);
	std::cout << std::endl;

	ScavTrap hey("ScavTrapper");
	hey.challengeNewcomer("toto");
	hey.challengeNewcomer("toto");
	hey.challengeNewcomer("toto");

	return (0);
}
