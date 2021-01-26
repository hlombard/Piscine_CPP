#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const & src) {
	this->_name = src.getName();
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	int i = -1;
	while (++i < 4) {
		if (i == 3 && this->_inventory[i])
			return;
		if (!this->_inventory[i])
			break;
	}
	this->_inventory[i] = m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter & target) {
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
	}
}

Character & Character::operator=(Character const & src) {
	this->_name = src.getName();
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}
