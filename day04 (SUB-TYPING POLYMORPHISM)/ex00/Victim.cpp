#include "Victim.hpp"

Victim::Victim(std::string name) : name(name) {
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const & src) {
	*this = src;
}

std::string Victim::getName(void) const
{
	return (this->name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}

Victim & Victim::operator=(Victim const & src) {
	if (this != &src) {
		this->name = src.getName();
	}
	return (*this);
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

std::ostream & operator<<(std::ostream & out, Victim const & src)
{
    out << "I'm " << src.getName() << " and I like otters!" << std::endl;
    return out;
}
