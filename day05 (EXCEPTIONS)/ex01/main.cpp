#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat joe("Joe", 150);
	Bureaucrat rogan("Rogan", 3);

	std::cout << joe;
	std::cout << rogan;

	try {
		joe.downgrade();
		rogan.upgrade();
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	Form *topform;
	Form *lowform;
	Form *badform;

	try {
		topform = new Form("topform", 1, 1);
		lowform = new Form("lowform", 139, 139);
		badform = new Form("badform", 302, 4);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << *topform;
	std::cout << *lowform << std::endl;

	std::cout << rogan;
	rogan.signForm(*topform);
	rogan.upgrade();
	rogan.upgrade();
	std::cout << rogan << std::endl;
	rogan.signForm(*topform);
	rogan.signForm(*topform);

	delete topform;
	delete lowform;
}
