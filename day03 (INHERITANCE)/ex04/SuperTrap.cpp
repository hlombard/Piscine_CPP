#include "SuperTrap.hpp"

static void printSpawn(std::string name, unsigned int level, unsigned int hp) {
	std::cout	<< "[SUP4-TP] \"" << name
				<< "\" lvl(" << level << ") se ramène "
				<< "avec " << hp << " points de vie!"
				<< std::endl;
}

SuperTrap::SuperTrap(void) : ClapTrap()
{
	this->hitPoints = 100; //this->FragTrap::hitPoints;
	this->maxHitPoints = 100; //this->FragTrap::maxHitPoints;
	this->energyPoints = 120; //this->NinjaTrap::energyPoints;
	this->maxEnergyPoints = 120; //this->NinjaTrap::maxEnergyPoints;
	this->level = 1;
	this->name = name;
	this->meleeAttackDamage = 60; //this->NinjaTrap::meleeAttackDamage;
	this->rangedAttackDamage = 20; //this->FragTrap::rangedAttackDamage;
	this->armorDamageReduction = 5; //this->FragTrap::armorDamageReduction;

	std::cout << "#SuperTrap constructor called" << std::endl;
	printSpawn(this->name, this->level, this->hitPoints);
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100; //this->FragTrap::hitPoints;
	this->maxHitPoints = 100; //this->FragTrap::maxHitPoints;
	this->energyPoints = 120; //this->NinjaTrap::energyPoints;
	this->maxEnergyPoints = 120; //this->NinjaTrap::maxEnergyPoints;
	this->level = 1;
	this->name = name;
	this->meleeAttackDamage = 60; //this->NinjaTrap::meleeAttackDamage;
	this->rangedAttackDamage = 20; //this->FragTrap::rangedAttackDamage;
	this->armorDamageReduction = 5; //this->FragTrap::armorDamageReduction;

	std::cout << "#SuperTrap constructor called" << std::endl;
	printSpawn(this->name, this->level, this->hitPoints);
}

SuperTrap::SuperTrap(SuperTrap const & src) {
	std::cout << "#SuperTrap constructor called" << std::endl;
	*this = src;
	return;
}

void	SuperTrap::rangedAttack(std::string const &target)
{
	std::cout << "SuperTrap calls FragTrap's rangedAttack" << std::endl;
	return (FragTrap::rangedAttack(target));
}

void	SuperTrap::meleeAttack(std::string const &target)
{
	std::cout << "SuperTrap calls NinjaTrap's rangedAttack" << std::endl;
	return (NinjaTrap::meleeAttack(target));
}

void SuperTrap::printInfo(void) {
	std::cout << "hp: " << this->hitPoints << std::endl;
	std::cout << "max hp: " << this->maxHitPoints << std::endl;
	std::cout << "nrg: " << this->energyPoints << std::endl;
	std::cout << "max nrg: " << this->maxEnergyPoints << std::endl;
	std::cout << "level: " << this->level << std::endl;
	std::cout << "name: " << this->name << std::endl;
	std::cout << "meleeAttack: " << this->meleeAttackDamage << std::endl;
	std::cout << "rangedAttack: " << this->rangedAttackDamage << std::endl;
	std::cout << "armorReduction: " << this->armorDamageReduction << std::endl;
	std::cout << std::endl;
}


SuperTrap & SuperTrap::operator=(SuperTrap const & src) {
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

SuperTrap::~SuperTrap(void) {
	std::cout << "#SuperTrap destructor called" << std::endl;
}
