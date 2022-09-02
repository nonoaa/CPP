#include "Form.hpp"

Form::Form() : name_(""), signGrade_(0), executeGrade_(0) {}

Form::Form(const std::string name, const int signGrade, const int executeGrade) : name_(name), signGrade_(signGrade), executeGrade_(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooLowException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooHighException();
}

Form::Form(const Form &src) : name_(src.name_), signGrade_(src.signGrade_), executeGrade_(src.executeGrade_)
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	isSigned_ = src.isSigned_;
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (name_);
}

bool Form::getSign() const
{
	return (isSigned_);
}

int Form::getSignGrade() const
{
	return (signGrade_);
}

int Form::getExecuteGrade() const
{
	return (executeGrade_);
}

void Form::beSigned(const Bureaucrat &brc)
{
	if (signGrade_ < brc.getGrade())
	{
		isSigned_ = false;
		throw GradeTooLowException();
	}
	isSigned_ = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > executeGrade_)
		throw GradeTooLowException();
	action(executor);
	std::cout << executor.getName() << " executed " << getName() << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Form &ref)
{
	out << ref.getName() << ", signGrade "
		<< ref.getSignGrade() << ", executeGrade "
		<< ref.getExecuteGrade() << ", isSigned "
		<< ref.getSign() << std::endl;
	return (out);
}