#include "Array_tpp.hpp"

template <typename T>
const char *Array<T>::OutOfLimitException::what(void) const throw() {
	return ("Array Exception: Out Of Limit!");
}

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {return;}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_data = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(Array const & src) {
	if (src._size) {
		this->_size = src._size;
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_data[i] = src._data[i];
		}
	}
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (this->_size);
}

template <typename T>
T & Array<T>::operator[](unsigned int n) {
	if (n >= this->_size)
		throw Array::OutOfLimitException();
	return (this->_data[n]);
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & src) {
	if (this->_data)
		delete[] this->_data;
	this->_size = src.size();

	if (this->_size) {
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_data[i] = src._data[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void) {
	if (this->_data)
		delete[] this->_data;
}
