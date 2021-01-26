#include "Character.hpp"

Character::Character(std::string const & name) :
_name(name),
_ap(40),
_weapon(NULL)
{
	return;
}

Character::Character(Character const & src) {
	*this = src;
}


void Character::recoverAP(void) {
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if (!this->_weapon || this->_ap == 0)
		return;

	this->_ap -= this->_weapon->getAPCost();
	if (this->_ap < 0)
		this->_ap = 0;

	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;

	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() == 0) {
		delete (enemy);
	}
}

std::string const & Character::getName(void) const {
	return (this->_name);
}

int Character::getAp(void) const {
	return (this->_ap);
}

AWeapon *Character::getWeapon(void) const {
	return (this->_weapon);
}


Character & Character::operator=(Character const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_ap = src.getAp();
		this->_weapon = src.getWeapon();
	}
	return (*this);
}

Character::~Character(void) {return;}

std::ostream & operator<<(std::ostream & out, Character const & src) {
	if (!src.getWeapon())
		out << src.getName() << " has " << src.getAp() << " AP and is unarmed" << std::endl;
	else
		out << src.getName() << " has " << src.getAp() << " AP and wields a " << src.getWeapon()->getName() << std::endl;
	return (out);
}
