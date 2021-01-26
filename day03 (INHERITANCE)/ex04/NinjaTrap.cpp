#include "NinjaTrap.hpp"

static void printAttack(std::string name, std::string target, std::string type, unsigned int damage) {
	std::cout	<< "[NINJ4-TP] \"" << name << "\" attaque \"" << target
				<< "\" " << type << ", causant " << damage
				<< " points de dégâts !" << std::endl;
}

NinjaTrap::NinjaTrap(void) : ClapTrap() {
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;

	std::cout << "#NinjaTrap constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;

	std::cout << "#NinjaTrap constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
	*this = src;
	return;
}

void NinjaTrap::rangedAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son shuriken", this->rangedAttackDamage);
}

void NinjaTrap::meleeAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son katana", this->meleeAttackDamage);
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap) {

	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Ca se fatigue vite un NinjaTrap, me faut un peu de repos..."
					<< std::endl;
		return;
	}
	std::cout << "[NINJ4-TP] \"" << this->name << "\"" << " Jette sa chaussure au visage de \"" << trap.getName() << "\"" << std::endl;
	trap.takeDamage(3);
	this->energyPoints -= 25;
}


void NinjaTrap::ninjaShoebox(FragTrap &trap) {
	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Ca se fatigue vite un NinjaTrap, me faut un peu de repos..."
					<< std::endl;
		return;
	}
	std::cout << "[NINJ4-TP] \"" << this->name << "\"" << " Lance une roche sur \"" << trap.getName() << "\"" << std::endl;
	trap.takeDamage(10);
	this->energyPoints -= 25;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap) {
	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Ca se fatigue vite un NinjaTrap, me faut un peu de repos..."
					<< std::endl;
		return;
	}
	std::cout << "[NINJ4-TP] \"" << this->name << "\"" << " bondit et mord \"" << trap.getName() << "\"" << std::endl;
	trap.takeDamage(22);
	this->energyPoints -= 25;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap) {
	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Ca se fatigue vite un ClapTrap, me faut un peu de repos..."
					<< std::endl;
		return;
	}
	std::cout << "[NINJ4-TP] \"" << this->name << "\"" << " Lance un shuriken sur \"" << trap.getName() << "\"" << std::endl;
	trap.takeDamage(44);
	this->energyPoints -= 25;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & src) {
	if (this != &src) {
		this->hitPoints = src.hitPoints;
		this->maxHitPoints = src.maxHitPoints;
		this->energyPoints = src.energyPoints;
		this->maxEnergyPoints = src.maxEnergyPoints;
		this->level = src.level;
		this->name = src.name;
		this->meleeAttackDamage = src.meleeAttackDamage;
		this->rangedAttackDamage = src.rangedAttackDamage;
		this->armorDamageReduction = src.armorDamageReduction;
	}
	return (*this);
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "#NinjaTrap destructor called" << std::endl;
}
