#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

#include <stddef.h>

class Squad : public ISquad {

	private:
		int _count;
		ISpaceMarine **_ptr;

	public:
		Squad(void);
		Squad(Squad const & src);

		int getCount(void) const;
		ISpaceMarine *getUnit(int) const;
		int push(ISpaceMarine *marine);

		Squad & operator=(Squad const & src);

		~Squad(void);
};

#endif
