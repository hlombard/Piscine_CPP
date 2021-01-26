#include "Enemy.hpp"

Enemy::Enemy(void) {return;}

Enemy::Enemy(int hp, std::string const & type) :
hp(hp),
type(type)
{
	return;
}

Enemy::Enemy(Enemy const & src) {
	*this = src;
}

int Enemy::getHP(void) const {
	return (this->hp);
}

std::string const & Enemy::getType(void) const {
	return (this->type);
}

void Enemy::takeDamage(int damage) {
	if (damage < 0)
		return;
	if (damage > this->hp)
		damage = this->hp;
	this->hp -= damage;
}

Enemy & Enemy::operator=(Enemy const & src) {
	if (this != &src) {
		this->hp = src.getHP();
		this->type = src.getType();
	}
	return (*this);
}

Enemy::~Enemy(void) {return;}
