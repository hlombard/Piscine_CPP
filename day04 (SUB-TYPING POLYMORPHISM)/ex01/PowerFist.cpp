#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src) {return;}

void PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & src) {
	if (this != &src) {
		this->name = src.getName();
		this->damage = src.getDamage();
		this->apcost = src.getAPCost();
	}
	return (*this);
}

PowerFist::~PowerFist(void) {return;}
