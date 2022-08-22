#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain_ = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	brain_ = src.brain_;
	brain_ = new Brain(*(src.brain_));
	std::cout << "Cat copy operator called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	type = src.type;
	brain_ = new Brain(*(src.brain_));
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain_;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow~ meow~~~~" << std::endl;
}

Brain *Cat::getBrain()
{
	return (brain_);
}