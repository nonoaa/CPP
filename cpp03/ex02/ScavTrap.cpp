#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap " << name_ << " default constructor called."<< std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap " << name_ << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    name_ = src.name_;
    hitPoints_ = src.hitPoints_;
    energyPoints_ = src.energyPoints_;
    attackDamage_ = src.attackDamage_;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0)
    {
    	std::cout << "ScavTrap " << name_ << "has no EnergyPoints." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << name_ << " attacks "
                << target << ", causing " << attackDamage_
                << " points of damage!" << std::endl;
        energyPoints_--;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name_ << " is in Gate keeper mode."<< std::endl;
}