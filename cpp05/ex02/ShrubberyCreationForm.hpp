#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm():Form("", 0, 0){};
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm();
	virtual void action(Bureaucrat const &executor) const;
};

#endif