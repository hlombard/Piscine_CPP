#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		AMateria *_materia[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);

		void learnMateria(AMateria*);
		AMateria *createMateria(std::string const & type);

		MateriaSource & operator=(MateriaSource const & src);

		virtual ~MateriaSource(void);
};

#endif
