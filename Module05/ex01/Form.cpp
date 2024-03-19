#include "Form.hpp"

Form::Form() : _name(NULL), _gradeToSign(0), _gradeToExecute(0) //IMPORTANT: l'ordre des variables doit suivre l'ordre dans le .hpp. Puisque gradeToSign apparait avant gradeToExecute alors elle doit être initialisée avant!!
{
	_isSigned = false;
}

Form::~Form()
{
}

Form::Form(Form const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

Form &Form::operator=(Form const &rhs)
{
	_isSigned = rhs._isSigned;
	return *this;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_isSigned = false;
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the bureaucrat's grade cannot be higher than 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the bureaucrat's grade is too low to sign the form");
}

std::string Form::getName()
{
	return _name;
}

unsigned int Form::getGradeToSign()
{
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute()
{
	return _gradeToExecute;
}

bool Form::getIsSigned()
{
	return _isSigned;
}

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &output, Form &Form)
{
	output <<"Form name : " << Form.getName() << ", Grade to sign : " << Form.getGradeToSign() << ", Grade to execute : " << Form.getGradeToExecute() <<std::endl;
	return (output);
}