#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string _type;
		std::string _name;
	public:
		Zombie(void);
		void setName(std::string name);
		void setType(std::string type);
		void announce(void) const;
		~Zombie(void);
};

#endif
