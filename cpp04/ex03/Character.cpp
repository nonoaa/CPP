#include "Character.hpp"

Character::Character(std::string const &name) : name_(name)
{
	for (int i = 0; i < 4; i++)
	{
		materias_[i] = nullptr;
	}
}

Character::Character(Character const &src) : name_(src.name_)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.materias_[i] == nullptr)
			materias_[i] = nullptr;
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
		if (src.materias_[i] == nullptr)
			materias_[i] = nullptr;
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
		if (materias_[i] != nullptr)
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
		if (materias_[i] == nullptr)
		{
			materias_[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	materias_[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (materias_[idx] != nullptr)
		materias_[idx]->use(target);
}