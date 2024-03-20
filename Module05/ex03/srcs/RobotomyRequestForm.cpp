#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default Name")
{
}

RobotomyRequestForm::~RobotomyRequestForm() //IMPORTANT: undefined reference to `vtable for RobotomyRequestForm' --> qd j'oublie de mettre une variable qui est dans le .hpp dans le .cpp
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target)
{
	//IMPORTANT: AForm(copy) ligne au dessus
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) /* : _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute) */
{
	_target = rhs._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	static int i; //pas besoin de l''initialiser? //CHECK

	std::cout <<"ZZZZZZZZZZZZ" <<std::endl;

	if (i % 2 == 0)
		std::cout <<_target <<" has been robotomized successfully." <<std::endl;
	else
		std::cout <<"The robotomy failed." <<std::endl;
	i++;
}