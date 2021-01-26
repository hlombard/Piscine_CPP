#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string _type;
		std::string _name;

	public:
		Zombie(std::string type, std::string name);
		void announce(void) const;
		~Zombie(void);
};

#endif
