#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name_;
	AMateria *materias_[4];
	bool is_equipped[4];
	Character();

public:
	Character(std::string const &name);
	Character(Character const &src);
	Character &operator=(Character const &src);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};

#endif