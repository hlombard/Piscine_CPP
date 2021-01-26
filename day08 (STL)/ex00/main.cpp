#include "easyfind.hpp"

#include <iostream>

int main(void) {

	// Vector test not found
	std::vector<int> vect_1(5, 1);
	try {
		std::cout << "Searching value 9:" << std::endl;
		std::cout << "Found value " << easyfind(vect_1, 9) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Vector test found
	std::vector<int> vect_2;
	vect_2.push_back(9);
	vect_2.push_back(0);
	vect_2.push_back(-9);
	vect_2.push_back(42);
	try {
		std::cout << "Searching value 42:" << std::endl;
		std::cout << "Found value " << easyfind(vect_2, 42) << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// List test not found
	std::list<int> list_1(5, 10);
	try {
		std::cout << "Searching value 7:" << std::endl;
		std::cout << "Found value " << easyfind(list_1, 7) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// List test found
	std::list<int> list_2;
	list_2.push_back(48);
	list_2.push_back(9);
	list_2.push_back(21);
	list_2.push_back(33);
	try {
		std::cout << "Searching value 21:" << std::endl;
		std::cout << "Found value " << easyfind(list_2, 21) << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}
