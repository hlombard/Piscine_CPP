#include "Fixed.class.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << Fixed::n_bits);
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << Fixed::n_bits)));
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	 std::cout << "Assignation operator called" << std::endl;
	 this->_value = rhs.getRawBits();
	 return (*this);
}

std::ostream & operator<<(std::ostream &out, Fixed const & value) {
	out << value.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)getRawBits() / (1 << Fixed::n_bits));
}

int Fixed::toInt(void) const {
	return (getRawBits() >> Fixed::n_bits);
}


Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
