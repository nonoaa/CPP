#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *new_Z = new Zombie(name);

    return new_Z;
}