#include "Serialization.hpp"

int main(void) {

	Serialization ser;

	// Original random data
	std::cout << "Original data:" << std::endl;
	std::cout << "\t s1: [" << ser.data->s1 << "]" << std::endl;
	std::cout << "\t n: [" << ser.data->n << "]" << std::endl;
	std::cout << "\t s2: [" << ser.data->s2 << "]" << std::endl;
	std::cout << std::endl;

	void *p = ser.serialize();
	Data *data = ser.deserialize(p);

	// Deserialized data
	std::cout << "Deserialized data:" << std::endl;
	std::cout << "\t s1: [" << data->s1 << "]" << std::endl;
	std::cout << "\t n: [" << data->n << "]" << std::endl;
	std::cout << "\t s2: [" << data->s2 << "]" << std::endl;

	delete data;
	delete[] static_cast<char *>(p);

	return (0);
}
