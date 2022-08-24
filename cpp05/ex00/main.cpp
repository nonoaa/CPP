#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("byahn", 2);

	try
	{
		b.increaseGrade();
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat c("messi", 149);
	try
	{
		c.decreaseGrade();
		std::cout << c << std::endl;
		c.decreaseGrade();
		std::cout << c << std::endl;
		c.decreaseGrade();
		std::cout << c << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;
	
	try
	{
		Bureaucrat d("Ronaldo", -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}