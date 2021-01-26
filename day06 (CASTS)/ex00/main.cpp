#include "ScalarConversion.hpp"

int usage(void) {
	std::cout << "usage: ./convert [value]" << std::endl;
	return (1);
}

int main(int ac, char **av) {

	if (ac != 2)
		return (usage());

	ScalarConversion convert(av[1]);
	convert.printChar();
	convert.printInt();
	convert.printFloat();
	convert.printDouble();

	return (0);
}
