#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.name_), grade_(src.grade_) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
	grade_ = src.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return (name_);
}

int Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::increaseGrade()
{
	if (grade_ - 1 < 1)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decreaseGrade()
{
	if (grade_ + 1 > 150)
		throw GradeTooLowException();
	grade_++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (out);
}