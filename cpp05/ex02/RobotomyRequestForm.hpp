#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <random>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm():Form("", 0, 0){};
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm();
	virtual void action(Bureaucrat const &executor) const;
};

#endif