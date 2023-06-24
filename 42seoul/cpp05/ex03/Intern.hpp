#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private: 
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	
public:
	Intern();

	Form *makeForm(std::string const &name, std::string const &target);

	~Intern();
};

#endif