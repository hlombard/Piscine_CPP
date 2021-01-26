#include "Zombie.hpp"


Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name) {
	return;
}

void Zombie::announce(void) const {
	std::cout << "<" << this->_name << " (" << this->_type << ")> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "\t<" << this->_name << " (" << this->_type << ")> died...";
	std::cout << std::endl;
}
