#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
hitPoints(100),
maxHitPoints(100),
energyPoints(100),
maxEnergyPoints(100),
level(1),
name("default"),
meleeAttackDamage(30),
rangedAttackDamage(20),
armorDamageReduction(5)
{
	std::cout << "#ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
hitPoints(100),
maxHitPoints(100),
energyPoints(100),
maxEnergyPoints(100),
level(1),
name(name),
meleeAttackDamage(30),
rangedAttackDamage(20),
armorDamageReduction(5)
{
	std::cout << "#ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "#ClapTrap constructor called" << std::endl;
	*this = src;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {

	int tmpAmount = (int)amount;

	if (tmpAmount <= 0) {
		std::cout << "[CL4P-TP] ERROR: impossible de heal une valeur négative ou zero" << std::endl;
		return;
	}

	if (this->hitPoints == this->maxHitPoints) {
		std::cout << "[CL4P-TP] Warning: impossible de heal d'avantage \"" << this->name << "\"" << std::endl;
		return;
	}

	if (amount + this->hitPoints > this->maxHitPoints) {
		amount = this->maxHitPoints - this->hitPoints;
	}

	this->hitPoints += amount;
	std::cout	<< "[CL4P-TP] \"" << this->name << "\" s'est heal de "
				<< amount << " points de vie => " << this->hitPoints
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	int tmpAmount, tmpHp, damageTaken;

	if (this->hitPoints == 0) {
		std::cout << "[CL4P-TP] Warning: \"" << this->name << "\"" << " est déjà mort..." << std::endl;
		return;
	}

	tmpAmount = (int)amount;
	if (tmpAmount <= 0) {
		std::cout << "[CL4P-TP] ERROR: impossible d'infliger des dégats négatifs ou zero" << std::endl;
		return;
	}

	if (tmpAmount - (int)this->armorDamageReduction <= 0) {
		std::cout << "[CL4P-TP] Warning: aucun dégâts infligés à \"" << this->name << "\" grace à son armure" << std::endl;
		return;
	}

	tmpHp = (int)this->hitPoints - tmpAmount + (int)this->armorDamageReduction;
	if ((tmpHp <= 0) || (this->armorDamageReduction > this->hitPoints)) {
		damageTaken = this->hitPoints;
		this->hitPoints = 0;
	}
	else {
		damageTaken = tmpAmount - (int)this->armorDamageReduction;
		this->hitPoints = (unsigned int)tmpHp;
	}

	std::cout	<< "[CL4P-TP] \"" << this->name << "\" a pris " << damageTaken
				<< " points de dégâts! => " << this->hitPoints << " restants. ";
	if (this->hitPoints == 0)
		std::cout << "Il est MORT!!!";
	std::cout << std::endl;
}


ClapTrap & ClapTrap::operator=(ClapTrap const & src) {
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

ClapTrap::~ClapTrap(void) {
	std::cout << "#ClapTrap destructor called" << std::endl;
}
