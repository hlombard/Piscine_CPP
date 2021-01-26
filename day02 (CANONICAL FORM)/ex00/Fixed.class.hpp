#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

	private:
		int _value;
		static int const n_bits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const & src);

		Fixed & operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		~Fixed(void);
};


#endif
