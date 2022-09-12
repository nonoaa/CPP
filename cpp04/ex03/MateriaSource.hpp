#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias_[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &src);

	virtual ~MateriaSource();
	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif