#include "Pony.hpp"

#include <iostream>
#include <string>

void Pony::setName(std::string name) {
	this->_name = name;
}

void Pony::introduce(void) const {
	std::cout << "\tHi I'm a pony named " << this->_name << std::endl;
}

Pony::~Pony(void) {
	std::cout << "\tPony " << this->_name << " destroyed" << std::endl;
}
