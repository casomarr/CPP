#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	_gradeToSign = rhs._grade;
	_gradeToExecute = rhs._grade;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 25)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (gradeToExecute > 5)
		throw PresidentialPardonForm::GradeTooLowException();
}

RobotomyRequestForm(std::string target): _target(target)
{

	//HERE
}