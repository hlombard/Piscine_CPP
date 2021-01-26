#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <string>
#include <iostream>

class ScalarConversion {

	private:
		ScalarConversion(void);
		std::string _padding(void) const;

		std::string _value;

	public:
		ScalarConversion(std::string input);
		ScalarConversion(ScalarConversion const & src);

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;

		void printChar(void) const;
		void printInt(void) const;
		void printFloat(void) const;
		void printDouble(void) const;

		class ImpossibleException : public std::exception {
			virtual const char *what(void) const throw();
		};

		class NonDisplayableException : public std::exception {
			virtual const char *what(void) const throw();
		};

		ScalarConversion & operator=(ScalarConversion const & src);

		virtual ~ScalarConversion(void);
};

#endif
