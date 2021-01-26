#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim {

	protected:
		Victim(void);
		std::string name;

	public:
		Victim(std::string name);
		Victim(Victim const & src);

		std::string getName(void) const;
		virtual void getPolymorphed(void) const;

		Victim & operator=(Victim const & src);

		virtual ~Victim(void);

};

std::ostream & operator<<(std::ostream & out, Victim const & src);

#endif
