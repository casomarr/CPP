#include "../includes/AForm.hpp"

AForm::AForm() : _name(NULL), _gradeToSign(0), _gradeToExecute(0)
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
		throw AForm::GradeTooLowException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High : shouldn't exceed 150");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low : shouldn't be under 1 or under the AForm's grade to sign");
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
	output <<"AForm name : " << AForm.getName() << ", Grade to sign : " << AForm.getGradeToSign() << ", Grade to execute : " << AForm.getGradeToExecute() <<std::endl;
	return (output);
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("This form is no signed.");
}