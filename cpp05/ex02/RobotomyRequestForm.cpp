#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	Form::operator=(src);
	return (*this);
}

void RobotomyRequestForm::action(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	std::cout << "drrrrrrrrrrr.........." << std::endl;
	if (dis(gen))
	{
		std::cout << getName() << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << getName() << " has been failed robotomizing." << std::endl;
	}
	
}

RobotomyRequestForm::~RobotomyRequestForm() {}