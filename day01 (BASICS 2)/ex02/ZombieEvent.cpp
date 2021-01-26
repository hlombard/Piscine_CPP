#include "ZombieEvent.hpp"


void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) const {
	return (new Zombie(this->_type, name));
}

/* need to call srand(time(NULL)) before calling this func to ensure randomness */
void	ZombieEvent::randomChump(void) const {
	std::string name[6] = {
		"Zomboy",
		"Jacky",
		"Roger",
		"Joe",
		"Toto",
		"Rocco",
	};

	Zombie random(this->_type, name[rand() % 6]);
	random.announce();
}
