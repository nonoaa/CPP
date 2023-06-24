#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name_("noname"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): name_(src.name_), hitPoints_(src.hitPoints_), energyPoints_(src.energyPoints_), attackDamage_(src.attackDamage_)
{
    std::cout << "Copy constructor called" << std::endl;
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
    std::cout << name_ << " take " << amount << " damage!";
	if (hitPoints_ < amount)
		hitPoints_ = 0;
    else
	    hitPoints_ -= amount;
    std::cout << " Current Hit Points: " << hitPoints_ << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ == 0)
    {
    	std::cout << "ClapTrap " << name_ << "has no EnergyPoints." << std::endl;
    }
    else
    {
        std::cout << name_ << " is repaired " << amount << " hit points!";
        hitPoints_ += amount;
        std::cout << " Current Hit Points: " << hitPoints_ << std::endl;
        energyPoints_--;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}