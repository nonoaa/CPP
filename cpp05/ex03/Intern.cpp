#include "Intern.hpp"

Intern::Intern() {}

Form *Intern::makeForm(std::string const &name, std::string const &target)
{
	Form *out;

	std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = -1;

	while (str[++i] != name && i < 3)
		;

	switch (i)
	{
		case 0:
			out = new ShrubberyCreationForm(target);
			return out;
		case 1:
			out = new RobotomyRequestForm(target);
			return out;
		case 2:
			out = new PresidentialPardonForm(target);
			return out;
		default:
			std::cout << target <<" form is not exist." << std::endl;
			return 0;
	}
}

Intern::~Intern() {}