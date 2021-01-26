#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon) {
	return;
}

std::string const & Weapon::getType(void) const {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
