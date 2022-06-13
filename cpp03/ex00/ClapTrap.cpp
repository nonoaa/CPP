#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    name_ = "noname";
    hitPoints_ = 10;
    energyPoints_ = 10;
    attackDamage_ = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << "Constructor called" << std::endl;
    name_ = name;
    hitPoints_ = 10;
    energyPoints_ = 10;
    attackDamage_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    name_ = src.name_;
    hitPoints_ = src.hitPoints_;
    energyPoints_ = src.energyPoints_;
    attackDamage_ = src.attackDamage_;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0)
    {
    	std::cout << "ClapTrap " << name_ << "has no EnergyPoints." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name_ << " attacks "
                << target << ", causing " << attackDamage_
                << " points of damage!" << std::endl;
        energyPoints_--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << name_ << " take " << amount << " damage!" << std::endl;
	if (hitPoints_ < amount)
		hitPoints_ = 0;
    else
	    hitPoints_ -= amount;

}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ == 0)
    {
    	std::cout << name_ << "has no EnergyPoints." << std::endl;
    }
    else
    {
        std::cout << name_ << " be repaired " << amount << " hit points!" << std::endl;
        hitPoints_ += amount;
        energyPoints_--;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}