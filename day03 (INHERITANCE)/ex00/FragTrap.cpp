#include "FragTrap.hpp"

static void printAttack(std::string name, std::string target, std::string type, unsigned int damage) {
	std::cout	<< "[FR4G-TP] \"" << name << "\" attaque \"" << target
				<< "\" " << type << ", causant " << damage
				<< " points de dégâts !" << std::endl;
}

static void printSpawn(std::string name, unsigned int level, unsigned int hp) {
	std::cout	<< "[FR4G-TP] \"" << name
				<< "\" lvl(" << level << ") a spawn "
				<< "avec " << hp << " points de vie!"
				<< std::endl;
}

void FragTrap::_speAttack0(std::string const & target) const {
	printAttack(this->_name, target, "avec ses poings", 1);
}

void FragTrap::_speAttack1(std::string const & target) const {
	printAttack(this->_name, target, "avec son.. grand baton!", 69);
}

void FragTrap::_speAttack2(std::string const & target) const {
	printAttack(this->_name, target, "avec ses coudes, pour impresionner Joe Rogan", 55);
}

void FragTrap::_speAttack3(std::string const & target) const {
	printAttack(this->_name, target, "avec ses boules en feu, des boules de feu pardon", this->_rangedAttackDamage);
}

void FragTrap::_speAttack4(std::string const & target) const {
	printAttack(this->_name, target, "à la mario cart, il jette une banane", 10);
}

FragTrap::FragTrap(void) :
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_name("default"),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	printSpawn(this->_name, this->_level, this->_hitPoints);
	std::srand(std::time(NULL));
	return;
}

FragTrap::FragTrap(std::string name) :
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_name(name),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	printSpawn(this->_name, this->_level, this->_hitPoints);
	std::srand(std::time(NULL));
	return;
}

FragTrap::FragTrap(FragTrap const & src) :
_hitPoints(src._hitPoints),
_maxHitPoints(src._maxHitPoints),
_energyPoints(src._energyPoints),
_maxEnergyPoints(src._maxEnergyPoints),
_level(src._level),
_name(src._name),
_meleeAttackDamage(src._meleeAttackDamage),
_rangedAttackDamage(src._rangedAttackDamage),
_armorDamageReduction(src._armorDamageReduction)
{
	printSpawn(this->_name, this->_level, this->_hitPoints);
	std::srand(std::time(NULL));
	return;
}

void FragTrap::rangedAttack(std::string const & target) const {
	printAttack(this->_name, target, "avec son arc", this->_rangedAttackDamage);
}

void FragTrap::meleeAttack(std::string const & target) const {
	printAttack(this->_name, target, "avec son épée", this->_meleeAttackDamage);
}

void FragTrap::beRepaired(unsigned int amount) {

	int tmpAmount = (int)amount;

	if (tmpAmount <= 0) {
		std::cout << "[FR4G-TP] ERROR: impossible de heal une valeur négative ou zero" << std::endl;
		return;
	}

	if (this->_hitPoints == this->_maxHitPoints) {
		std::cout << "[FR4G-TP] Warning: impossible de heal d'avantage \"" << this->_name << "\"" << std::endl;
		return;
	}

	if (amount + this->_hitPoints > this->_maxHitPoints) {
		amount = this->_maxHitPoints - this->_hitPoints;
	}

	this->_hitPoints += amount;
	std::cout	<< "[FR4G-TP] \"" << this->_name << "\" s'est heal de "
				<< amount << " points de vie => " << this->_hitPoints
				<< std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	int tmpAmount, tmpHp, damageTaken;

	if (this->_hitPoints == 0) {
		std::cout << "[FR4G-TP] Warning: \"" << this->_name << "\"" << " est déjà mort..." << std::endl;
		return;
	}

	tmpAmount = (int)amount;
	if (tmpAmount <= 0) {
		std::cout << "[FR4G-TP] ERROR: impossible d'infliger des dégats négatifs ou zero" << std::endl;
		return;
	}

	if (tmpAmount - (int)this->_armorDamageReduction <= 0) {
		std::cout << "[FR4G-TP] Warning: aucun dégâts infligés à \"" << this->_name << "\" grace à son armure" << std::endl;
		return;
	}

	tmpHp = (int)this->_hitPoints - tmpAmount + (int)this->_armorDamageReduction;
	if ((tmpHp <= 0) || (this->_armorDamageReduction > this->_hitPoints)) {
		damageTaken = this->_hitPoints;
		this->_hitPoints = 0;
	}
	else {
		damageTaken = tmpAmount - (int)this->_armorDamageReduction;
		this->_hitPoints = (unsigned int)tmpHp;
	}

	std::cout	<< "[FR4G-TP] \"" << this->_name << "\" a pris " << damageTaken
				<< " points de dégâts! => " << this->_hitPoints << " restants. ";
	if (this->_hitPoints == 0)
		std::cout << "Il est MORT!!!";
	std::cout << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	void (FragTrap::*random[5])(std::string const & target) const = {
		&FragTrap::_speAttack0,
		&FragTrap::_speAttack1,
		&FragTrap::_speAttack2,
		&FragTrap::_speAttack3,
		&FragTrap::_speAttack4};

	if (this->_energyPoints < 25) {
		std::cout	<< "\"" << this->_name << "\" "
					<< "Je suis claqué, me faut un peu de repos..."
					<< std::endl;
		return;
	}

	(this->*random[std::rand() % 5])(target);
	this->_energyPoints -= 25;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
	if (this != &src) {
		this->_hitPoints = src._hitPoints;
		this->_maxHitPoints = src._maxHitPoints;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_name = src._name;
		this->_meleeAttackDamage = src._meleeAttackDamage;
		this->_rangedAttackDamage = src._rangedAttackDamage;
		this->_armorDamageReduction = src._armorDamageReduction;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout	<< "[FR4G-TP] \"" << this->_name << "\" est définitivement mort"
				<< std::endl;
	return;
}
