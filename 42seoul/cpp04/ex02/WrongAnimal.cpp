#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "none";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): type(src.type)
{
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	type = src.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string const &WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}