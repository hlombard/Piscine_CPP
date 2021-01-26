#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n) : _n(n) {
	std::string name[6] = {
		"Zomboy",
		"Jacky",
		"Roger",
		"Joe",
		"Toto",
		"Rocco",
	};

	_horde = new Zombie[n];
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		_horde[i].setType("1");
		_horde[i].setName(name[rand() % 6]);
	}

	std::cout << "Created a Horde of " << n << " zombies" << std::endl;
}

void ZombieHorde::announce(void) const {
	for (int i = 0; i < this->_n; i++) {
		_horde[i].announce();
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete[] _horde;
	std::cout << "Woops! The whole Horde died suddently..." << std::endl;
}
