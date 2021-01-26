#include "Pony.hpp"

#include <iostream>

void ponyOnTheHeap()
{
	Pony *allocated = new Pony;

	allocated->setName("\"allocatoR\"");
	allocated->introduce();
	std::cout << "\tI'm located on the heap" << std::endl;
	delete allocated;
}

void ponyOnTheStack()
{
	Pony stack;

	stack.setName("\"StackzoR\"");
	stack.introduce();
	std::cout << "\tI'm located on the stack" << std::endl;
}

int main(void)
{
	std::cout << "calling ponyOnTheStack()" << std::endl;
	ponyOnTheStack();
	std::cout << "back to main scope" << std::endl << std::endl;

	std::cout << "calling ponyOnTheHeap()" << std::endl;
	ponyOnTheHeap();
	std::cout << "back to main scope" << std::endl;
	return (0);
}
