#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    name_ = name;
    weapon_ = nullptr;
}

void HumanB::setWeapon(Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack(void)
{
    if(weapon_)
        std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
    else
        std::cout << name_ << " attacks with his punch\n";
}