#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class Pony {
	private:
		std::string _name;

	public:
		void setName(std::string name);
		void introduce(void) const;
		~Pony(void);
};

#endif
