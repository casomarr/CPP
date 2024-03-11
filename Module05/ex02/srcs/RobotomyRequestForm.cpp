#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _gradeToSign(0), _gradeToExecute(0), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _target(copy._target)
{
	//IMPORTANT: AForm(copy) ligne au dessus
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) /* : _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute) */
{
/* 	_gradeToSign = rhs._gradeToSign;
	_gradeToExecute = rhs._gradeToExecute;
	_target = rhs._target; */
	(void)rhs;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 72)
		throw RobotomyRequestForm::GradeTooLowException();
	else if (gradeToExecute > 45)
		throw RobotomyRequestForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() < this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	static int i; //pas besoin de l''initialiser? //CHECK

	std::cout <<"ZZZZZZZZZZZZ" <<std::endl;

	if (i % 2 == 0)
		std::cout <<_target <<" has been robotomized successfully." <<std::endl;
	else
		std::cout <<"The robotomy failed." <<std::endl;
}