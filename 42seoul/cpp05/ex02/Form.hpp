#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name_;
	bool isSigned_;
	const int signGrade_;
	const int executeGrade_;
	Form();

public:
	Form(const std::string name, const int signGrade, const int executeGrade);
	Form(const Form &src);
	Form &operator=(const Form &src);
	virtual ~Form();

	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &brc);
	void execute(Bureaucrat const &executor) const;
	virtual void action(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception 
	{
	public:
		const char *what() const throw()
		{
			return ("Grade Too High");
		}
	};
	class GradeTooLowException : public std::exception 
	{
	public:
		const char *what() const throw()
		{
			return ("Grade Too Low");
		}
	};
};

std::ostream& operator<<(std::ostream &out, const Form &ref);

#endif