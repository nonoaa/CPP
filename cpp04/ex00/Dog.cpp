#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << "Dog copy operator called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	type = src.type;
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wall~ Wall~~~~" << std::endl;
}