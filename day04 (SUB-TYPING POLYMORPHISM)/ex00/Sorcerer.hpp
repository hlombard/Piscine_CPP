#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

#include <iostream>
#include <string>

class Sorcerer {

	private:
		Sorcerer(void);
		std::string _name;
		std::string _title;

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);

		std::string getName(void) const;
		std::string getTitle(void) const;
		void polymorph(Victim const & victim) const;

		Sorcerer & operator=(Sorcerer const & src);

		~Sorcerer(void);

};

std::ostream & operator<<(std::ostream & out, Sorcerer const & src);

#endif
