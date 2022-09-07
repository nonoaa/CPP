#include "Conversion.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "argument number error." << std::endl;
		return 0;
	}

	Conversion cv(av[1]);
	std::cout << cv;
	return 0;
}