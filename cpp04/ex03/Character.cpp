#include "Character.hpp"

Character::Character(std::string const &name) : name_(name)
{
	for (int i = 0; i < 4; i++)
	{
		materias_[i] = NULL;
		is_equipped[i] = false;
	}
}

Character::Character(Character const &src) : name_(src.name_)
{
	for (int i = 0; i < 4; i++)
	{
		is_equipped[i] = src.is_equipped[i];
		if (src.materias_[i] == NULL)
			materias_[i] = NULL;
		else
		{
			materias_[i] = src.materias_[i]->clone();
		}
	}
}

Character &Character::operator=(Character const &src)
{
	name_ = src.name_;
	for (int i = 0; i < 4; i++)
	{
		is_equipped[i] = src.is_equipped[i];
		if (src.materias_[i] == NULL)
			materias_[i] = NULL;
		else
		{
			materias_[i] = src.materias_[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias_[i] != NULL)
			delete materias_[i];
	}
}

std::string const &Character::getName() const
{
	return name_;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias_[i] == NULL)
		{
			materias_[i] = m;
			is_equipped[i] = true;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	is_equipped[idx] = false;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (materias_[idx] != NULL && is_equipped[idx] == true)
		materias_[idx]->use(target);
}