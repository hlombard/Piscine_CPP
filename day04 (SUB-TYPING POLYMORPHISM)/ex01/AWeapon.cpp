#include "AWeapon.hpp"

AWeapon::AWeapon(void) {return;}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::AWeapon(AWeapon const & src) {
	*this = src;
}

std::string const & AWeapon::getName(void) const {
	return (this->name);
}

int AWeapon::getDamage(void) const {
	return (this->damage);
}

int AWeapon::getAPCost(void) const {
	return (this->apcost);
}

AWeapon & AWeapon::operator=(AWeapon const & src) {
	if (this != &src) {
		this->name = src.getName();
		this->damage = src.getDamage();
		this->apcost = src.getAPCost();
	}
	return (*this);
}

AWeapon::~AWeapon(void) {return;}
