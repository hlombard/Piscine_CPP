#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src) {return;}

void PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & src) {
	if (this != &src) {
		this->name = src.getName();
		this->damage = src.getDamage();
		this->apcost = src.getAPCost();
	}
	return (*this);
}

PlasmaRifle::~PlasmaRifle(void) {return;}
