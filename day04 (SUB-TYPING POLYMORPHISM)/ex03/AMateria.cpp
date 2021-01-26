#include "AMateria.hpp"

AMateria::AMateria(void) {return;}

AMateria::AMateria(std::string const & type) : _xp(0), type(type)
{return;}

AMateria::AMateria(AMateria const & src) {
	*this = src;
}

std::string const & AMateria::getType(void) const {
	return (this->type);
}

unsigned int AMateria::getXP(void) const {
	return (this->_xp);
}

void AMateria::setXP(unsigned int xp) {
	this->_xp = xp;
}

void AMateria::use(ICharacter & target) {
	this->_xp += 10;
	(void)target;
}

AMateria & AMateria::operator=(AMateria const & src) {
	if (this != & src) {
		this->_xp = src.getXP();
		this->type = src.getType();
	}
	return (*this);
}

AMateria::~AMateria(void) {return;}
