#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;


	/* Extra tests */
	std::cout << std::endl;

	//Unarmed print and unarmed attack
	std::cout << "attack without weapons:" << std::endl;
	std::cout << *me;
	me->equip(NULL);
	std::cout << *me;
	me->attack(b);
	std::cout << "can't attack without weapons..." << std::endl << std::endl;

	//Recover HP;
	std::cout << "recover AP:" << std::endl;
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	std::cout << std::endl;

	//SuperMutant
	std::cout << "SuperMutant:" << std::endl;
	SuperMutant *super = new SuperMutant();
	std::cout << "SuperMutant HP: " << super->getHP() << std::endl;
	me->equip(pr);
	me->attack(super);
	std::cout << "SuperMutant HP: " << super->getHP() << std::endl;

	delete me;
	delete pr;
	delete pf;
	delete super;

	return 0;
}
