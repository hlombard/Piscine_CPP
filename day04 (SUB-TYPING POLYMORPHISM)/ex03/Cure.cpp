#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {return;}

Cure::Cure(Cure const & src) : AMateria(src) {return;}

AMateria *Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure & Cure::operator=(Cure const & src) {
	if (this != &src)
	{
		this->setXP(src.getXP());
	}
	return (*this);
}

Cure::~Cure(void) {return;}
