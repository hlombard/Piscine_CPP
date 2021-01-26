#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string const name) : _name(name), _wep(NULL) {
	return;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_wep = &weapon;
}

void HumanB::attack(void) const {
	std::cout << this->_name << " attacks with his ";
	if (this->_wep)
		std::cout << this->_wep->getType();
	else
		std::cout << "..woops! he just ruuuns awaaay";
	std::cout << std::endl;
}
