#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat byahn("byahn", 2);
	std::cout << byahn << std::endl;

	try
	{
		byahn.increaseGrade();
		std::cout << byahn << std::endl;
		byahn.increaseGrade();
		std::cout << byahn << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form formA("a", 10, 10);
	Form formB("b", 10, 10);
	byahn.signForm(formA);
	for (int i = 0; i < 10; i++)
	{
		byahn.decreaseGrade();
	}
	std::cout << byahn << std::endl;
	byahn.signForm(formB);
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

	return 0;
}