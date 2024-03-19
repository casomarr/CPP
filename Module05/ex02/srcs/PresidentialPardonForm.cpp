#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Default Name")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	_target = rhs._target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::cout <<_target <<" has been pardoned by Zaphod Beeblebrox." <<std::endl;
		std::cout <<executor.getName() <<" executed " <<this->getTarget() <<std::endl;

}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}