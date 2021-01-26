#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <stddef.h>
#include <string>
#include <iostream>

class ICharacter;

class AMateria {

	private:
		AMateria(void);
		unsigned int _xp;

	protected:
		std::string type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);

		std::string const & getType(void) const;
		unsigned int getXP(void) const;
		void setXP(unsigned int xp);
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

		AMateria & operator=(AMateria const & src);

		virtual ~AMateria(void);
};

#endif
