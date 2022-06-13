#include "FragTrap.hpp"

int main(void)
{
	FragTrap Yasuo("Yasuo");
    FragTrap Yone(Yasuo);

	Yasuo.attack("Teemo");
	Yasuo.takeDamage(100);
	Yasuo.beRepaired(3);
}