#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src) : Victim(src) {
	*this = src;
}

void Peon::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}

Peon & Peon::operator=(Peon const & src) {
	if (this != &src) {
		this->name = src.getName();
	}
	return (*this);
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}
