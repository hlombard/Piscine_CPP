#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>
#include <iostream>

class AWeapon {

	private:
		AWeapon(void);

	protected:
		std::string name;
		int damage;
		int apcost;

	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);

		std::string const & getName(void) const;
		int getDamage(void) const;
		int getAPCost(void) const;
		virtual void attack(void) const = 0;

		AWeapon & operator=(AWeapon const & src);

		virtual ~AWeapon(void);

};

#endif
