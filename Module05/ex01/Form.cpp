#include "Form.hpp"

Form::Form() : _name(NULL), _gradeToExecute(0), _gradeToSign(0)
{
	_isSigned = false;
}

Form::~Form()
{
}

Form::Form(Form const &copy) : _name(copy._name), _gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign)
{
	*this = copy;
}

Form &Form::operator=(Form const &rhs)
{
	_isSigned = rhs._isSigned;
	return *this;
}

Form::Form(std::string name, int gradeToExecute, int gradeToSign) : _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	_isSigned = false;
	if (gradeToSign < 1)
		throw Form::GradeTooLowException();
	else if (gradeToSign > 150)
		throw Form::GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High : shouldn't exceed 150");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low : shouldn't be under 1 or under the Form's grade to sign");
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
	_isSigned = true; //IMPORTANT: pas besoin de else car qd on throw une exception ça s'arrête direct
}

std::ostream	&operator<<(std::ostream &output, Form &Form)
{
	output <<"Form name : " << Form.getName() << ", Grade to sign : " << Form.getGradeToSign() << ", Grade to execute : " << Form.getGradeToExecute() <<std::endl;
	return (output);
}