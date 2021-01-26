#include "ScavTrap.hpp"

static void printAttack(std::string name, std::string target, std::string type, unsigned int damage) {
	std::cout	<< "[SC4V-TP] \"" << name << "\" attaque \"" << target
				<< "\" " << type << ", causant " << damage
				<< " points de dégâts !" << std::endl;
}

static void printSpawn(std::string name, unsigned int level, unsigned int hp) {
	std::cout	<< "[SC4V-TP] \"" << name
				<< "\" lvl(" << level << ") apparait soudainement "
				<< "avec " << hp << " points de vie!"
				<< std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;

	std::cout << "#ScavTrap constructor called" << std::endl;
	printSpawn(this->name, this->level, this->hitPoints);
	std::srand(time(NULL));
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;

	std::cout << "#ScavTrap constructor called" << std::endl;
	printSpawn(this->name, this->level, this->hitPoints);
	std::srand(time(NULL));
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	*this = src;
	return;
}

void ScavTrap::rangedAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son arbalète", this->rangedAttackDamage);
}

void ScavTrap::meleeAttack(std::string const & target) const {
	printAttack(this->name, target, "avec son couteau", this->meleeAttackDamage);
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	static std::string challenges[3] = {
		" doit combattre sans armes contre ",
		" doit se déplacer à cloche pied contre ",
		" doit se bander les yeux contre "
	};

	if (this->energyPoints < 25) {
		std::cout	<< "\"" << this->name << "\" "
					<< "Pas la foi de faire un challenge, me faut un peu de repos..."
					<< std::endl;
		return;
	}

	std::cout << "[SC4V-TP] \"" << this->name << "\"" << challenges[std::rand() % 3] << target << std::endl;
	this->energyPoints -= 25;

}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
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

ScavTrap::~ScavTrap(void) {
	std::cout << "#ScavTrap destructor called" << std::endl;
	std::cout	<< "[SC4V-TP] \"" << this->name << "\" est définitivement mort RIP"
				<< std::endl;
	return;
}
