#include "Span.hpp"

int main(void) {

	// Subject tests
	std::cout << "Subject test:" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// Extra tests
	std::cout << "Extra tests:" << std::endl << std::endl;

	// AddNumber with iterators:
	std::cout << "AddNumber with iterators:" << std::endl;
	std::vector<int> vect = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	Span more = Span(10);
	more.addNumber(vect.begin(), vect.end());
	std::cout << more.shortestSpan() << std::endl;
	std::cout << more.longestSpan() << std::endl;
	std::cout << std::endl;

	// Add too many values:
	std::cout << "Add too many values:" << std::endl;
	more.addNumber(9);
	std::cout << std::endl;

	// 10 000 values:
	std::cout << "10 000 values:" << std::endl;
	Span big = Span(10000);
	for (int i = 0; i < 10000; i++) {
		big.addNumber(i);
	}
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	std::cout << std::endl;

	// Empty
	Span empty = Span(10);
	try {
		std::cout << empty.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << " Not enough values to find shortest Span" << std::endl;
	}
	try {
		std::cout << empty.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << " Not enough values to find longest Span" << std::endl;
	}

}
