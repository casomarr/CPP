#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	_gradeToSign = rhs._grade;
	_gradeToExecute = rhs._grade;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 25)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (gradeToExecute > 5)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm(std::string target): _target(target)
{
	//HERE
}