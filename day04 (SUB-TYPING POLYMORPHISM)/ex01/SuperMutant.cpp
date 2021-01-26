#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) {
	*this = src;
}

void SuperMutant::takeDamage(int damage) {
	Enemy::takeDamage(damage - 3);
}

SuperMutant & SuperMutant::operator=(SuperMutant const & src) {
	if (this != &src) {
		this->hp = src.getHP();
		this->type = src.getType();
	}
	return (*this);
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh..." << std::endl;
}
