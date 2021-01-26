#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) :
_name(name),
_title(title)
{
	std::cout << this->_name << ", ";
	std::cout << this->_title << ", ";
	std::cout << "is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src) {
	*this = src;
}

std::string Sorcerer::getName(void) const {
	return (this->_name);
}

std::string Sorcerer::getTitle(void) const {
	return (this->_title);
}

void Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
}


std::ostream & operator << (std::ostream & out, Sorcerer const & value) {
	out << "I am " << value.getName() << ", ";
	out << value.getTitle() << ", ";
	out << "and I like ponies!" << std::endl;
	return (out);
}

Sorcerer & Sorcerer::operator=(Sorcerer const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_title = src.getTitle();
	}
	return (*this);
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", ";
	std::cout << this->_title << ", is dead. ";
	std::cout << "Consequences will never be the same!" << std::endl;
}
