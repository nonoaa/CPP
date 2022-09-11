#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    name_ = "noname";
    ClapTrap::name_ = name_ + "_clap_name";
    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;

    std::cout << "DiamondTrap " << name_ << " default constructor called."<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name)
{
    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;

    std::cout << "DiamondTrap " << name_ << " constructor called."<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name_(src.name_)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    name_ = src.name_;
    hitPoints_ = src.hitPoints_;
    energyPoints_ = src.energyPoints_;
    attackDamage_ = src.attackDamage_;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << name_ << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::name_ << std::endl;
}