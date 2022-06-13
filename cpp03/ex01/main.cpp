#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Yasuo("Yasuo");
    ScavTrap Yone(Yasuo);

	Yasuo.attack("Teemo");
	Yasuo.takeDamage(100);
	Yasuo.beRepaired(3);
}