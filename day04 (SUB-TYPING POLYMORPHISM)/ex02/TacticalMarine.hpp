#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {

	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);

		ISpaceMarine *clone(void) const;
		void battleCry(void) const;
		void rangedAttack(void) const;
		void meleeAttack(void) const;

		TacticalMarine & operator=(TacticalMarine const & src);

		~TacticalMarine(void);
};

#endif
