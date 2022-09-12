#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria(std::string const &type)
{
	type_ = type;
}

AMateria::AMateria(AMateria const &src) : type_(src.type_) {}

AMateria &AMateria::operator=(AMateria const &src)
{
	type_ = src.type_;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type_;
}
