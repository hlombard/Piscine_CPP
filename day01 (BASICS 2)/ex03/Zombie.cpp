#include "Zombie.hpp"


Zombie::Zombie() {return;}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::setType(std::string type) {
	this->_type = type;
}

void Zombie::announce(void) const {
	std::cout << "<" << this->_name << " (" << this->_type << ")> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "\t<" << this->_name << " (" << this->_type << ")> died...";
	std::cout << std::endl;
}
