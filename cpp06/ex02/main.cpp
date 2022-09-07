#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base *generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);

	int value = dis(gen);
	if (value == 0)
	{
		std::cout << "A created." << std::endl;
		return new A;
	}
	else if (value == 1)
	{
		std::cout << "B created." << std::endl;
		return new B;
	}
	else if (value == 2)
	{
		std::cout << "C created." << std::endl;
		return new C;
	}
	
	return 0;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	dynamic_cast<A &>(p);
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "===============test" << i + 1 << "===============" << std::endl;
		Base *p = generate();
		identify(p);
		identify(*p);
	}
	return 0;
}