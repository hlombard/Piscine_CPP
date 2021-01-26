#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {

	// create a Zombie and "kill" him
	std::cout << "1: Create a Zombie on the heap and kill him" << std::endl;
	Zombie *one = new Zombie("heap", "one");
	one->announce();
	delete one;
	std::cout << "Done!" << std::endl << std::endl;

	// create a Zombie on the heap with ZombieEvent
	std::cout << "2: Create a Zombie on the heap with ZombieEvent" << std::endl;
	ZombieEvent event;
	event.setZombieType("heap");
	Zombie *two = event.newZombie("two");
	two->announce();
	delete two;
	std::cout << "Done!" << std::endl << std::endl;

	// create 3 random Zombies on the stack with ZombieEvent
	srand(time(NULL));
	event.setZombieType("stack");
	std::cout << "3: Create 3 random zombies on the stack with ZombieEvent" << std::endl;
	for (int i = 0; i < 3; i++) {
		event.randomChump();
	}
	std::cout << "Done!" << std::endl;


	return (0);
}
