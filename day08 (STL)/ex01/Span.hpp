#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {

	private:
		Span(void);

		std::vector<int> _vec;
		unsigned int _maxsize;

	public:
		Span(unsigned int n);
		Span(Span const & src);

		class NoMoreSpaceException : public std::exception {
			virtual const char *what(void) const throw();
		};

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		Span & operator=(Span const & src);

		~Span(void);
};

#endif
