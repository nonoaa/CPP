#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 5 == 0)
			ideas[i] = "eat";
		else if (i % 5 == 1)
			ideas[i] = "sleep";
		else if (i % 5 == 2)
			ideas[i] = "run";
		else if (i % 5 == 3)
			ideas[i] = "jump";
		else if (i % 5 == 4)
			ideas[i] = "make sound";
	}
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = src.ideas[i];
	}
	std::cout << "Brain Copy assignment constructor called" << std::endl;
	return (*this);
}

void Brain::getIdea(int i)
{
	std::cout << ideas[i] << std::endl;
}

void Brain::setIdea(int i, std::string str)
{
	ideas[i] = str;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}