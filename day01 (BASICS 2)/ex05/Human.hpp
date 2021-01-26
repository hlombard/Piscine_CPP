#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>

#include "Brain.hpp"

class Human {

	private:
		const Brain _brain;

	public:
		Human(void);
		std::string identify(void) const;
		const Brain &getBrain(void) const;

};

#endif
