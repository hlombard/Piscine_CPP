#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

	private:
		Character(void);

		std::string _name;
		int _ap;
		AWeapon *_weapon;


	public:
		Character(std::string const & name);
		Character(Character const & src);

		std::string const & getName(void) const;
		int getAp(void) const;
		AWeapon *getWeapon(void) const;

		void recoverAP(void);
		void equip(AWeapon *weapon);
		void attack(Enemy *enemy);

		Character & operator=(Character const & src);

		~Character(void);

};

std::ostream & operator<<(std::ostream & out, Character const & src);

#endif
