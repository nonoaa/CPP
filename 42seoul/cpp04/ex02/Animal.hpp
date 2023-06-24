#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string const &getType() const;
};

#endif