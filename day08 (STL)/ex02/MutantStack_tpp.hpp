#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack(void) {return;}
		MutantStack(MutantStack const & src) {*this = src;}

		typedef typename std::deque<T>::const_iterator iterator;
		iterator begin(void) const {return this->c.begin();}
		iterator end(void) const {return this->c.end();}

		MutantStack & operator=(MutantStack const & src) {
			this->c = src.c;
			return (*this);
		}

		virtual ~MutantStack(void) {return;}
};

#endif
