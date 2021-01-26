#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {

	private:
		Peon(void);

	public:
		Peon(std::string name);
		Peon(Peon const & src);

		virtual void getPolymorphed(void) const;

		Peon & operator=(Peon const & src);

		virtual ~Peon(void);

};


#endif
