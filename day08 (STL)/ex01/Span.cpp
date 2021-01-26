#include "Span.hpp"

const char *Span::NoMoreSpaceException::what() const throw() {
	return ("NoMoreSpace Exception : Can't add more data");
}

Span::Span(unsigned int n)
{
	this->_maxsize = n;
}

Span::Span(Span const & src) {
	*this = src;
}

void Span::addNumber(int number) {
	try {
		if (this->_vec.size() >= this->_maxsize)
			throw NoMoreSpaceException();
		this->_vec.push_back(number);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	try {
		for (std::vector<int>::iterator it = start; it != end; it++)
		{
			if (this->_vec.size() >= this->_maxsize)
				throw NoMoreSpaceException();
			this->_vec.push_back(*it);
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int Span::shortestSpan(void) const {

	if (this->_vec.size() < 2)
		throw std::exception();

	int min = std::abs(this->_vec.begin() - this->_vec.end());
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		for (std::vector<int>::const_iterator jt = it+1; jt!= _vec.end(); jt++)
		{
			if (abs(*it - *jt) < min)
				min = std::abs(*it - *jt);
		}
	}

	return (min);
}

int Span::longestSpan(void) const {
	if (this->_vec.size() < 2)
		throw std::exception();

	int max = *std::max_element(this->_vec.begin(), this->_vec.end());
	int min = *std::min_element(this->_vec.begin(), this->_vec.end());
	return (max - min);
}


Span & Span::operator=(Span const & src) {
	this->_vec.clear();
	this->_vec = src._vec;
	this->_maxsize = src._maxsize;
	return (*this);

}

Span::~Span(void) {return;}
