#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &src);
	Cure &operator=(Cure const &src);
	virtual ~Cure() {};

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif