#include "Noob.hpp"

Noob::Noob(std::string name) : Victim(name) {
	std::cout << "Noob noob." << std::endl;
}

Noob::Noob(Noob const & src) : Victim(src) {
	*this = src;
}

void Noob::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a geek!" << std::endl;
}

Noob & Noob::operator=(Noob const & src) {
	if (this != &src) {
		this->name = src.getName();
	}
	return (*this);
}

Noob::~Noob(void) {
	std::cout << "atchoum..." << std::endl;
}

