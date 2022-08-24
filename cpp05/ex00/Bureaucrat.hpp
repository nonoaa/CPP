#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;
	Bureaucrat();

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat &operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();

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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &ref);

#endif