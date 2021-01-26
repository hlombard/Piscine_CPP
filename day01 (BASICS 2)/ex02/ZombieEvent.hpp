#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include "Zombie.hpp"

#include <string>

class ZombieEvent {

	private:
		std::string	_type;

	public:
		void	setZombieType(std::string type);
		Zombie *newZombie(std::string name) const;
		void	randomChump(void) const;
};

#endif
