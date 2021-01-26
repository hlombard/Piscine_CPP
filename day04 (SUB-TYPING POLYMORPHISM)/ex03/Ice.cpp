#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {return;}

Ice::Ice(Ice const & src) : AMateria(src) {return;}

AMateria *Ice::clone(void) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice & Ice::operator=(Ice const & src) {
	if (this != &src)
	{
		this->setXP(src.getXP());
	}
	return (*this);
}

Ice::~Ice(void) {return;}
