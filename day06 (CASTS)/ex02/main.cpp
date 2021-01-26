#include "Base_A_B_C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void) {
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "Created A" << std::endl;
		return (new A);
	}

	else if (i == 2)
	{
		std::cout << "Created B" << std::endl;
		return (new B);
	}

	else
	{
		std::cout << "Created C" << std::endl;
		return (new C);
	}
}

void identify_from_pointer(Base *p) {
	Base *base;

	if ((base = dynamic_cast<A*>(p)))
		std::cout << "A" << std::endl;
	else if ((base = dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	else if ((base = dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p) {
	identify_from_pointer(&p);
}


int main(void) {

	std::srand(std::time(NULL));

	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);

	delete base;
	return (0);
}
