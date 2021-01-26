#include "Fixed.class.hpp"
#include <iostream>

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl << std::endl;

	std::cout << "Arithmetics tests:" << std::endl;
	std::cout << a << " + " << b << " = " << a+b << std::endl;
	std::cout << a << " - " << b << " = " << a-b << std::endl;
	std::cout << a << " * " << b << " = " << a*b << std::endl;
	std::cout << a << " / " << b << " = " << a/b << std::endl;

	std::cout << "Comparison tests:" << std::endl;
	Fixed c(42);
	Fixed d(21);
	Fixed e(Fixed(21) * Fixed(2));
	if (c > d) {
		std::cout << c << " bigger than " << d << std::endl;
	}
	if (d < c) {
		std::cout << d << " lower than " << c << std::endl;
	}
	if (d != c) {
		std::cout << d << " different than " << c << std::endl;
	}
	if (e == c) {
		std::cout << e << " equal to " << c << std::endl;
	}
	if (e != d) {
		std::cout << e << " different than " << d << std::endl;
	}

	std::cout << "Max between " << e << " and " << d << " is " << Fixed::max(e,d) << std::endl;

	return (0);
}
