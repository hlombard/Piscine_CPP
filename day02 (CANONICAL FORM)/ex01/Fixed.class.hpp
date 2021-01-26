#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _value;
		static int const n_bits = 8;

	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);

		Fixed & operator=(Fixed const & rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		~Fixed(void);
};

std::ostream & operator<<(std::ostream &out, Fixed const & value);


#endif
