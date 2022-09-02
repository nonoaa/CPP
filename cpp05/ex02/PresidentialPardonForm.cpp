#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src), target_(src.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	Form::operator=(src);
	return (*this);
}

void PresidentialPardonForm::action(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}