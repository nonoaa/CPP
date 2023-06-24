#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat byahn("byahn", 2);
	std::cout << byahn << std::endl;

	// ShrubberyCreationForm tree("tree");
	// try
	// {
	// 	tree.execute(byahn);
	// 	Bureaucrat asd("asd", 138);
	// 	std::cout << asd << std::endl;
	// 	tree.execute(asd);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// RobotomyRequestForm rr("drill");
	// try
	// {
	// 	rr.execute(byahn);
	// 	Bureaucrat asd("asd", 138);
	// 	std::cout << asd << std::endl;
	// 	rr.execute(asd);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	// PresidentialPardonForm pp("pardonform");
	// try
	// {
	// 	pp.execute(byahn);
	// 	byahn.executeForm(pp);
	// 	Bureaucrat asd("asd", 138);
	// 	std::cout << asd << std::endl;
	// 	pp.execute(asd);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	Intern a;
	Form *b;
	try
	{
		b= a.makeForm("shrubbery creation", "asd");
		b->execute(byahn);
		delete(b);

		b = a.makeForm("robotomy request", "dddd");
		b->execute(byahn);
		delete(b);

		b = a.makeForm("presidential pardon", "sdsdsd");
		b->execute(byahn);
		delete(b);

		b = a.makeForm("pr", "dddd");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}