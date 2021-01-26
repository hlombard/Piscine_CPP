#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Constructor grade Exception:" << std::endl << "\t";
	try {
		Bureaucrat("lowgrade", 220);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl << "\t";
	}

	try {
	Bureaucrat("highgrade", -2);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Upgrade Exception:" << std::endl << "\t";
	try {
		Bureaucrat up("best of the best", 3);
		std::cout << up << "\t";
		up.upgrade();
		std::cout << up << "\t";
		up.upgrade();
		std::cout << up << "\t";
		up.upgrade();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Downgrade Exception:" << std::endl << "\t";
	try {
		Bureaucrat down("worst of the worst", 148);
		std::cout << down << "\t";
		down.downgrade();
		std::cout << down << "\t";
		down.downgrade();
		std::cout << down << "\t";
		down.downgrade();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
