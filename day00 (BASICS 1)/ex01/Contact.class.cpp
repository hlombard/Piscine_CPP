#include "Contact.class.hpp"

#include <iostream>
#include <string>

Contact::Contact(void) {
	for (int i = 0; i < 11; i++) {
		this->infos[i] = "";
	}
}

void Contact::setInfo(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << this->_fields[i] << ": ";
		getline(std::cin, this->infos[i]);
	}

}

void Contact::printInfo(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << this->_fields[i] << ": ";
		if (this->infos[i].find_first_not_of(' ') != std::string::npos)
			std::cout << this->infos[i] << std::endl;
		else
			std::cout << "(NULL)" << std::endl;
	}
}

Contact::~Contact(void) {
	return;
}
