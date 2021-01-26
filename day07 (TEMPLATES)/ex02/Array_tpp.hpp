#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <string>
#include <iostream>
# include <cctype>

template <typename T>
class Array {

	private:
		T *_data;
		unsigned int _size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const & src);

		class OutOfLimitException : public std::exception {
			virtual const char *what(void) const throw();
		};

		unsigned int size(void) const;

		T & operator[](unsigned int n);
		Array & operator=(Array const & src);

		virtual ~Array(void);
};

#endif
