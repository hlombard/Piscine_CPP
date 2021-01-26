#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"


int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << std::endl << "#Extra tests" << std::endl;

	ISquad *squad = new Squad;
	ISpaceMarine *assault = new AssaultTerminator;
	ISpaceMarine *tactical = new TacticalMarine;
	std::cout << std::endl;

	// Add members to squad with clone();
	std::cout << "Squad count = " << squad->getCount() << std::endl;
	std::cout << "#Pushing new members" << std::endl;
	for (int i = 0; i < 5; i++) {
		squad->push(assault->clone());
		squad->push(tactical->clone());
	}
	std::cout << "Squad count = " << squad->getCount() << std::endl << std::endl;

	// Push same members
	std::cout << "#Pushing same members:" << std::endl;
	squad->push(squad->getUnit(squad->getCount()));
	squad->push(squad->getUnit(squad->getCount()));
	std::cout << "Squad count = " << squad->getCount() << std::endl << std::endl;

	// Checking content;
	std::cout << "#Checking squad's content:" << std::endl;
	for (int i = 0; i < squad->getCount(); i++) {
		ISpaceMarine *tmp = squad->getUnit(i);
		tmp->meleeAttack();
	}
	std::cout << std::endl;

	//Squad = operator
	std::cout << "#Squad = operator" << std::endl;
	ISquad *anotherSquad = squad;
	std::cout << "Copy Squad count = " << anotherSquad->getCount() << std::endl << std::endl;
	for (int i = 0; i < anotherSquad->getCount(); i++) {
		ISpaceMarine *tmp = anotherSquad->getUnit(i);
		tmp->meleeAttack();
	}
	std::cout << std::endl;

	//Squad copy constructor
	std::cout << "#Squad copy constructor" << std::endl;
	ISquad *copy(squad);
	std::cout << "Copy Squad count = " << copy->getCount() << std::endl << std::endl;
	for (int i = 0; i < copy->getCount(); i++) {
		ISpaceMarine *tmp = copy->getUnit(i);
		tmp->meleeAttack();
	}

	delete squad;
	delete assault;
	delete tactical;

	return 0;
}
