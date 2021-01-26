#ifndef ZOMBIE_HPPORDE_HPP
# define ZOMBIE_HPPORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

	private:
		int _n;
		Zombie *_horde;
	public:
		ZombieHorde(int n);
		void announce(void) const ;
		~ZombieHorde(void);

};

#endif
