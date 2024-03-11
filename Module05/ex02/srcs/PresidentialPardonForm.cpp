#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _gradeToSign(0), _gradeToExecute(0), _target("")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void)rhs;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 25)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (gradeToExecute > 5)
		throw PresidentialPardonForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() < this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::cout <<_target <<" has been pardoned by Zaphod Beeblebrox." <<std::endl;
}