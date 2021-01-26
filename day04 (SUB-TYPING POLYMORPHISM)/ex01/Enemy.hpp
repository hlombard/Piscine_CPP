#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>
#include <iostream>

class Enemy {

	protected:
		Enemy(void);

		int hp;
		std::string type;

	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);

		int getHP(void) const;
		std::string const & getType(void) const;
		virtual void takeDamage(int damage);

		Enemy & operator=(Enemy const & src);

		virtual ~Enemy(void);

};

#endif
