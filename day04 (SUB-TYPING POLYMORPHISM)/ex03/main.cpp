#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// More tests
	std::cout << std::endl;

	// Materia default tests
	std::cout << "#Test Materia" << std::endl;
	MateriaSource materia;
	materia.learnMateria(new Ice());
	materia.learnMateria(new Ice());
	AMateria *ama = materia.createMateria("toto");
	if (!ama)
		std::cout << "no materia toto" << std::endl;
	ama = materia.createMateria("ice");
	if (ama)
	{
		std::cout << "created materia Ice" << std::endl;
		delete ama;
	}
	std::cout << std::endl;

	// equip / unequip / use
	std::cout << "#Test equip / unequip / use" << std::endl;
	Character toto("toto");

	toto.use(9, toto);
	toto.use(-1, toto);
	toto.unequip(2);
	Ice *ice = new Ice();
	toto.equip(ice);
	toto.use(0, toto);
	std::cout << "unequip ice" << std::endl;
	toto.unequip(0);
	toto.use(0, toto);
	delete ice;
	std::cout << std::endl;

	// Character copy/asignation
	std::cout << "#Test Character copy/asignation" << std::endl;
	toto.equip(new Cure());
	Character titi(toto);
	std::cout << titi.getName() << std::endl;
	titi.use(0, toto);
	Character bobo = toto;
	bobo.use(0, titi);
	std::cout << bobo.getName() << std::endl;
	std::cout << std::endl;

	// Materia copy/asignation
	std::cout << "#Materia copy/asignation" << std::endl;
	MateriaSource mama;
	mama.learnMateria(new Ice());
	mama.learnMateria(new Cure());
	MateriaSource same = mama;
	MateriaSource copy(mama);

	AMateria *test = same.createMateria("ice");
	AMateria *test2 = copy.createMateria("cure");
	std::cout << "toto equip asignation materia" << std::endl;
	toto.equip(test);
	toto.use(0, titi);
	std::cout << "toto equip copy materia" << std::endl;
	toto.equip(test2);
	toto.use(1, titi);

	return 0;
}
