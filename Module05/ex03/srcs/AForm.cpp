#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default Name"), _gradeToSign(0), _gradeToExecute(0)
{
	_isSigned = false;
}

AForm::~AForm()
{
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

AForm &AForm::operator=(AForm const &rhs)
{
	_isSigned = rhs._isSigned;
	return *this;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_isSigned = false;
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("the bureaucrat's grade cannot be higher than 1");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("the bureaucrat's grade is too low to sign the form");
}

std::string AForm::getName() const
{
	return _name;
}

unsigned int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

void	AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &output, AForm &AForm)
{
	output <<"Form name : " << AForm.getName() << ", Grade to sign : " << AForm.getGradeToSign() << ", Grade to execute : " << AForm.getGradeToExecute() <<std::endl;
	return (output);
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("the form is not signed.");
}