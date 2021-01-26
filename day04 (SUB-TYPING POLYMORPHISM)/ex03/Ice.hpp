#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(Ice const & src);

		AMateria* clone(void) const;
		void use(ICharacter & target);

		Ice & operator=(Ice const & src);

		virtual ~Ice(void);
};

#endif
