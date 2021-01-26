#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

#include <string>

class HumanA {

	private:
		std::string _name;
		Weapon &_wep;

	public:
		HumanA(std::string const name, Weapon &club);
		void attack(void) const;

};

#endif
