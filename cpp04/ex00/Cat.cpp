#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Cat copy operator called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	type = src.type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow~ meow~~~~" << std::endl;
}