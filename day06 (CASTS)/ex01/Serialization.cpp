#include "Serialization.hpp"

Data *random_init(void) {
	Data *data = new Data;

	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	std::srand(time(NULL));
	char str[9] = {0};

	// Generate random s1
	for (int i = 0; i < 8; ++i) {
		str[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];
		}

	str[8] = 0;
	std::string s1fmt(str);
	data->s1 = s1fmt;

	// Generate random number
	data->n = std::rand();

	// Generate random s2
	for (int i = 0; i < 8; ++i) {
		str[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];
	}
	str[8] = 0;
	std::string s2fmt(str);
	data->s2 = s2fmt;

	return (data);
}

Serialization::Serialization(void) : data(random_init()) {return;}

Serialization::Serialization(Serialization const & src) {
	*this = src;
}

void *Serialization::serialize(void) {
	char *data = new char[20];

	int i = 0;
	int index = 0;

	while (i < 8)
		data[i++] = this->data->s1[index++];

	*reinterpret_cast<int*>(data+8) = this->data->n;

	index = 0;
	i += 4;
	while (i < 20)
		data[i++] = this->data->s2[index++];

	return (data);
}

Data *Serialization::deserialize(void *raw) {
	Data *data = new Data;
	char *str;

	str = reinterpret_cast<char*>(raw);
	data->s1 = std::string(str, 8);
	data->n = *reinterpret_cast<int*>(str+8);
	data->s2 = std::string(str+12, 8);

	return (data);
}

Serialization & Serialization::operator=(Serialization const & src) {
	(void)src;
	return (*this);
}

Serialization::~Serialization(void) {
	delete this->data;
}
