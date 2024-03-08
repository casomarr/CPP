#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	_gradeToSign = rhs._grade;
	_gradeToExecute = rhs._grade;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 25)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (gradeToExecute > 5)
		throw PresidentialPardonForm::GradeTooLowException();
}

ShrubberyCreationForm(std::string target): _target(target)
{
	//HERE
}