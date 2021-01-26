#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

class Serialization {

	public:
		Data *data;

		Serialization(void);
		Serialization(Serialization const & src);

		void *serialize(void);
		Data *deserialize(void *raw);

		Serialization & operator=(Serialization const & src);

		~Serialization(void);
};

#endif
