#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Noob.hpp"

int main(void) {

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	// tests with another derived class
	std::cout << std::endl;
	Noob noob("noobito");
	robert.polymorph(noob);
	std::cout << std::endl;


	return 0;
}
