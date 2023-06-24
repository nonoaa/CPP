#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Yasuo("Yasuo");
    ScavTrap Yone(Yasuo);

	Yasuo.attack("Teemo");
	Yasuo.takeDamage(6);
	Yasuo.beRepaired(3);
}