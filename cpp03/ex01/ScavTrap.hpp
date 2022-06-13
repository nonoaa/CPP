#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &src);
    virtual ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif