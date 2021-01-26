#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

#include <string>
#include <stddef.h>

class Character : public ICharacter {

	private:
		Character(void);
		std::string _name;
		AMateria *_inventory[4];

	public:
		Character(std::string name);
		Character(Character const & src);
		std::string const & getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character & operator=(Character const & src);

		~Character(void);

};

#endif
