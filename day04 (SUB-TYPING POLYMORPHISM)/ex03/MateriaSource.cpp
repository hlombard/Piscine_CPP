#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++) {
		if (src._materia[i])
			this->_materia[i] = src._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}


void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;

	for (int i = 0; i < 4; i++) {
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}


MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
	if (this != & src)
	{
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i])
				delete this->_materia[i];
		}

		for (int i = 0; i < 4; i++) {
			if (src._materia[i])
				this->_materia[i] = src._materia[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i])
			delete this->_materia[i];
	}
}
