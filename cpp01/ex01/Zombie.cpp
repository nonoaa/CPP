#include "Zombie.hpp"

Zombie::Zombie(void)
{
    name_ = "zombie";
}

Zombie::~Zombie()
{
    std::cout << "<" << name_ << "> " << "died..." << std::endl;
}

void Zombie::setName(std::string name)
{
    name_ = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << name_ << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}