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

ScavTrap::ScavTrap(void) :
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_level(1),
_name("default"),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	printSpawn(this->_name, this->_level, this->_hitPoints);
	std::srand(time(NULL));
	return;
}

ScavTrap::ScavTrap(std::string name) :
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_level(1),
_name(name),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	printSpawn(this->_name, this->_level, this->_hitPoints);
	std::srand(time(NULL));
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
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
	std::srand(time(NULL));
	return;
}

void ScavTrap::rangedAttack(std::string const & target) const {
	printAttack(this->_name, target, "avec son arbalète", this->_rangedAttackDamage);
}

void ScavTrap::meleeAttack(std::string const & target) const {
	printAttack(this->_name, target, "avec son couteau", this->_meleeAttackDamage);
}

void ScavTrap::beRepaired(unsigned int amount) {

	int tmpAmount = (int)amount;

	if (tmpAmount <= 0) {
		std::cout << "[SC4V-TP] ERROR: impossible de heal une valeur négative ou zero" << std::endl;
		return;
	}

	if (this->_hitPoints == this->_maxHitPoints) {
		std::cout << "[SC4V-TP] Warning: impossible de heal d'avantage \"" << this->_name << "\"" << std::endl;
		return;
	}

	if (amount + this->_hitPoints > this->_maxHitPoints) {
		amount = this->_maxHitPoints - this->_hitPoints;
	}

	this->_hitPoints += amount;
	std::cout	<< "[SC4V-TP] \"" << this->_name << "\" s'est heal de "
				<< amount << " points de vie => " << this->_hitPoints
				<< std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	int tmpAmount, tmpHp, damageTaken;

	if (this->_hitPoints == 0) {
		std::cout << "[SC4V-TP] Warning: \"" << this->_name << "\"" << " est déjà mort..." << std::endl;
		return;
	}

	tmpAmount = (int)amount;
	if (tmpAmount <= 0) {
		std::cout << "[SC4V-TP] ERROR: impossible d'infliger des dégats négatifs ou zero" << std::endl;
		return;
	}

	if (tmpAmount - (int)this->_armorDamageReduction <= 0) {
		std::cout << "[SC4V-TP] Warning: aucun dégâts infligés à \"" << this->_name << "\" grace à son armure" << std::endl;
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

	std::cout	<< "[SC4V-TP] \"" << this->_name << "\" a pris " << damageTaken
				<< " points de dégâts! => " << this->_hitPoints << " restants. ";
	if (this->_hitPoints == 0)
		std::cout << "Il est MORT!!!";
	std::cout << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target) {

	static std::string challenges[3] = {
		" doit combattre sans armes contre ",
		" doit se déplacer à cloche pied contre ",
		" doit se bander les yeux contre "
	};

	if (this->_energyPoints < 25) {
		std::cout	<< "\"" << this->_name << "\" "
					<< "Pas la foi de faire un challenge, me faut un peu de repos..."
					<< std::endl;
		return;
	}

	std::cout << "[SC4V-TP] \"" << this->_name << "\"" << challenges[std::rand() % 3] << target << std::endl;
	this->_energyPoints -= 25;

}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
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

ScavTrap::~ScavTrap(void) {
	std::cout	<< "[SC4V-TP] \"" << this->_name << "\" est définitivement mort RIP"
				<< std::endl;
	return;
}
