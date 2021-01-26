#ifndef ANNUAIREZERO_CLASS_HPP
# define ANNUAIREZERO_CLASS_HPP

#include "Contact.class.hpp"

#include <iostream>
#include <string>
#include <limits>

class AnnuaireZero {
	private:
		int _contacts_nb;
		Contact _contacts[8];
		void _printHeader(void);

	public:
		AnnuaireZero(void);
		void welcome(void);
		void badCmd(std::string command);
		void search(void);
		void addContact(void);
		~AnnuaireZero(void);
};

#endif
