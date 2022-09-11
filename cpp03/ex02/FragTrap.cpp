#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap " << name_ << " default constructor called."<< std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap " << name_ << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    name_ = src.name_;
    hitPoints_ = src.hitPoints_;
    energyPoints_ = src.energyPoints_;
    attackDamage_ = src.attackDamage_;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0)
    {
    	std::cout << "FragTrap " << name_ << " has no EnergyPoints." << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name_ << " attacks "
                << target << ", causing " << attackDamage_
                << " points of damage!" << std::endl;
        energyPoints_--;
    }
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << name_ << " is doing highfive."<< std::endl;
}