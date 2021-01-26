#include "Squad.hpp"

Squad::Squad(void) : _count(0), _ptr(NULL) {return;}

Squad::Squad(Squad const & src) {
	int count = src.getCount();
	if (src._ptr)
	{
		this->_ptr = new ISpaceMarine*[count];
		for (int i = 0; i < count; i++) {
			this->push(src.getUnit(i)->clone());
		}
	}
	else
		this->_ptr = NULL;
	this->_count = count;
}

int Squad::getCount(void) const {
	return (this->_count);
}

ISpaceMarine *Squad::getUnit(int nb) const {
	if (nb < 0 || nb >= this->getCount())
		return (NULL);

	return (this->_ptr[nb]);
}

int Squad::push(ISpaceMarine *marine) {
	int count = this->getCount();

	if (marine == NULL)
		return (count);

	for (int i = 0; i < count; i++) {
		if (this->_ptr[i] == marine)
			return (count);
	}

	ISpaceMarine **new_ptr = new ISpaceMarine*[count + 1];
	for (int i = 0; i < count; i++) {
		new_ptr[i] = this->_ptr[i];
	}
	new_ptr[count] = marine;
	delete[] this->_ptr;
	this->_ptr = new_ptr;
	this->_count += 1;
	return (count + 1);

}

Squad & Squad::operator=(Squad const & src) {
	int count = this->getCount();
	if (this->_ptr)
	{
		for (int i = 0; i < count; i++) {
			delete this->_ptr[i];
		}
		delete[] this->_ptr;
		this->_count = 0;

		for (int i = 0; i < src.getCount(); i++) {
			this->push(src.getUnit(i)->clone());
		}
	}
	return (*this);
}

Squad::~Squad(void) {
	if (this->_ptr)
	{
		int count = this->getCount();

		for (int i = 0; i < count; i++) {
			delete this->_ptr[i];
		}
		delete[] this->_ptr;
	}
}
