#include "MutantStack_tpp.hpp"

int main()
{

	// Subject tests
	std::cout << "Subject tests:" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	// Extra tests
	std::cout << "Extra tests:" << std::endl << std::endl;

	// std::string
	MutantStack<std::string> mstr;
	mstr.push("Hello world!");
	mstr.push("toto");
	mstr.push("This piscine is almost done :]");

	// print content
	MutantStack<std::string>::iterator it1 = mstr.begin();
	MutantStack<std::string>::iterator it2 = mstr.end();
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;

	// pop
	mstr.pop();

	// print content
	it1 = mstr.begin();
	it2 = mstr.end();
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;

	// Asignation
	std::cout << "Asignation:" << std::endl;
	MutantStack<std::string> random;
	random = mstr;
	it1 = random.begin();
	it2 = random.end();
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;

	// Copy constructor
	std::cout << "Copy constructor:" << std::endl;
	MutantStack<std::string> another(random);
	it1 = another.begin();
	it2 = another.end();
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		it1++;
	}

	return 0;
}
