#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		materias_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.materias_[i] == NULL)
			materias_[i] = NULL;
		else
		{
			materias_[i] = src.materias_[i]->clone();
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.materias_[i] == NULL)
			materias_[i] = NULL;
		else
		{
			materias_[i] = src.materias_[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias_[i] != NULL)
			delete materias_[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias_[i] == NULL)
		{
			materias_[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias_[i] != NULL && materias_[i]->getType() == type)
		{
			return materias_[i]->clone();
		}
	}
	return 0;
}