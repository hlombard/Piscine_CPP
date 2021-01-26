#include "Fixed.class.hpp"

Fixed::Fixed(void) : _value(0) {return;}

Fixed::Fixed(int const value) {
	setRawBits(value << Fixed::n_bits);
}

Fixed::Fixed(float const value) {
	setRawBits(roundf(value * (1 << Fixed::n_bits)));
}

Fixed::Fixed(Fixed const & src) { *this = src; }

Fixed & Fixed::operator=(Fixed const & rhs) {
	 this->_value = rhs.getRawBits();
	 return (*this);
}

bool Fixed::operator>(Fixed const & ref) const {
	return (this->_value > ref.getRawBits());
}

bool Fixed::operator<(Fixed const & ref) const {
	return (this->_value < ref.getRawBits());
}

bool Fixed::operator>=(Fixed const & ref) const {
	return (this->_value >= ref.getRawBits());
}

bool Fixed::operator<=(Fixed const & ref) const {
	return (this->_value <= ref.getRawBits());
}

bool Fixed::operator==(Fixed const & ref) const {
	return (this->_value == ref.getRawBits());
}

bool Fixed::operator!=(Fixed const & ref) const {
	return (this->_value != ref.getRawBits());
}

/* Arithmetics */

Fixed Fixed::operator+(Fixed const & ref) const {
	Fixed ret;
	ret.setRawBits(this->_value + ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(Fixed const & ref) const {
	Fixed ret;
	ret.setRawBits(this->_value - ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(Fixed const & ref) const {
	Fixed ret;
	ret.setRawBits(this->_value * ref.getRawBits() >> Fixed::n_bits);
	return (ret);
}

Fixed Fixed::operator/(Fixed const & ref) const {
	Fixed ret;
	ret.setRawBits((this->_value << Fixed::n_bits) / ref.getRawBits());
	return (ret);
}

/* Pre Inc and Dec */

Fixed & Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed & Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

/* Post Inc and Dec */

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
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
	return ((float)getRawBits() / (float)(1 << Fixed::n_bits));
}

int Fixed::toInt(void) const {
	return (getRawBits() >> Fixed::n_bits);
}

/* Non member statics funcs */

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

/* Destructor */

Fixed::~Fixed(void) {return;}
