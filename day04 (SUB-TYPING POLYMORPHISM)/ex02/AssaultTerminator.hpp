#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine {

	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);

		ISpaceMarine *clone(void) const;
		void battleCry(void) const;
		void rangedAttack(void) const;
		void meleeAttack(void) const;

		AssaultTerminator & operator=(AssaultTerminator const & src);

		~AssaultTerminator(void);
};

#endif
