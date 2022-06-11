#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie *new_Z = newZombie(name);
    new_Z->announce();

    delete new_Z;
}