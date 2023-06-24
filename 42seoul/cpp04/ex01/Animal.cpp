#include "Animal.hpp"

Animal::Animal()
{
	type = "none";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src): type(src.type)
{
	std::cout << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	type = src.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string const &Animal::getType() const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}