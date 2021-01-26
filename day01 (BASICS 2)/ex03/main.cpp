#include "ZombieHorde.hpp"

int main(void) {

	std::cout << "Creating Horde..." << std::endl;
	ZombieHorde horde(10);
	std::cout << "Announcing horde..." << std::endl;
	horde.announce();
	std::cout << "Horde announced!" << std::endl;
	return (0);
}
