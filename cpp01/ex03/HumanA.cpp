#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}