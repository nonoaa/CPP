#include "Harl.hpp"

int getHarlFilter(std::string msg)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == msg)
			return (i);
	}
	return (4);
}

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "argument number error.\n";
        return (1);
    }
    Harl harl;

	switch (getHarlFilter(av[1]))
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}

	return (0);
}