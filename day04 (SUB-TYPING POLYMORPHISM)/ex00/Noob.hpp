#ifndef NOOB_HPP
# define NOOB_HPP

#include "Victim.hpp"

class Noob : public Victim {

	protected:
		Noob(void);

	public:
		Noob(std::string name);
		Noob(Noob const & src);

		virtual void getPolymorphed(void) const;

		Noob & operator=(Noob const & src);

		virtual ~Noob(void);
};

#endif
