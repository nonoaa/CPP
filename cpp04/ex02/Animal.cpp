#include "Animal.hpp"

Animal::Animal()
{
	type = "none";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src): type(src.type)
{
	std::cout << "Copy operator called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	type = src.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const &Animal::getType() const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}