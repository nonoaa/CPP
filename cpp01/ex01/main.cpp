#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 3;
	
	horde = zombieHorde(N, "Garrosh");
	for(int i = 0; i < N; i++)
	{
		horde->announce();
	}
	delete[] horde;

	return (0);
}