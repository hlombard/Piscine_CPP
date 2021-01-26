#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string const name, Weapon &club) : _name(name), _wep(club) {
	return;
}

void HumanA::attack(void) const {
	std::cout << this->_name << " attacks with his " << this->_wep.getType() << std::endl;
}
