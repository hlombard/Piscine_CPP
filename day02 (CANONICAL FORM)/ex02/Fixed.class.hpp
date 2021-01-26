#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _value;
		static int const n_bits = 8;

	public:
		/* Constructors */
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);

		/* Comparisons */
		bool operator>(Fixed const & ref) const;
		bool operator<(Fixed const & ref) const;
		bool operator>=(Fixed const & ref) const;
		bool operator<=(Fixed const & ref) const;
		bool operator==(Fixed const & ref) const;
		bool operator!=(Fixed const & ref) const;

		/* Arithmetics */
		Fixed operator+(Fixed const & ref) const;
		Fixed operator-(Fixed const & ref) const;
		Fixed operator*(Fixed const & ref) const;
		Fixed operator/(Fixed const & ref) const;
		Fixed & operator=(Fixed const & rhs);

		/* Pre Inc and Dec */
		Fixed & operator++(void);
		Fixed & operator--(void);

		/* Post Inc and Dec */
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		/* Non member statics funcs */
		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed const & max(Fixed const &a, Fixed const &b);
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);

		/* Destructors */
		~Fixed(void);
};

std::ostream & operator<<(std::ostream &out, Fixed const & value);

#endif
