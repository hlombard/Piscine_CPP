#include "FragTrap.hpp"

static void printAttack(std::string name, std::string target, std::string type, unsigned int damage) {
	std::cout	<< "[FR4G-TP] \"" << name << "\" attaque \"" << target
				<< "\" " << type << ", causant " << damage
				<< " points de dégâts !" << std::endl;
}

void FragTrap::_speAttack0(std::string const & target) const {
	printAttack(this->name, target, "avec ses poings", 1);
}

void FragTrap::_speAttack1(std::string const & target) const {
	printAttack(this->name, target, "avec son.. grand baton!", 69);
}

void FragTrap::_speAttack2(std::string const & target) const {
	printAttack(this->name, target, "avec ses coudes, pour impresionner Joe Rogan", 55);
}

void FragTrap::_speAttack3(std::string const & target) const {
	printAttack(this->name, target, "avec ses boules en feu, des boules de feu pardon", this->rangedAttackDamage);
}

void FragTrap::_speAttack4(std::string const & target) const {
	printAttack(this->name, target, "à la mario cart, il jette une banane", 10);
}

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;

	std::cout << "#FragTrap constructor called" << std::endl;
	std::srand(time(NULL));
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;

	std::cout << "#FragTrap constructor called" << std::endl;
	std::srand(time(NULL));
	return;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "#FragTrap constructor called" << std::endl;
	*this = src;
	return;
}

void FragTrap::rangedAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son arc", this->rangedAttackDamage);
}

void FragTrap::meleeAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son épée", this->meleeAttackDamage);
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	void (FragTrap::*random[5])(std::string const & target) const = {
		&FragTrap::_speAttack0,
		&FragTrap::_speAttack1,
		&FragTrap::_speAttack2,
		&FragTrap::_speAttack3,
		&FragTrap::_speAttack4};

	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Je suis claqué, me faut un peu de repos..."
					<< std::endl;
		return;
	}

	(this->*random[std::rand() % 5])(target);
	this->energyPoints -= 25;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
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

FragTrap::~FragTrap(void) {
	std::cout << "#FragTrap destructor called" << std::endl;
	return;
}
