#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

Ice::Ice(Ice const &src) : AMateria(src) {}

Ice &Ice::operator=(Ice const &src)
{
	AMateria::operator=(src);
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}