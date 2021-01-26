#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) {
	*this = src;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & src) {
	if (this != &src) {
		this->hp = src.getHP();
		this->type = src.getType();
	}
	return (*this);
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}
