#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default Name")
{
}

RobotomyRequestForm::~RobotomyRequestForm() //IMPORTANT: "error: undefined reference to `vtable for RobotomyRequestForm'" --> when forgot to write a variable that figures in the .hpp inside the .cpp
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
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
		
	static int i; //GRAMMAR: in c++, static int are automatically initialized to 0

	std::cout <<"ZZZZZZZZZZZZ" <<std::endl;

	if (i % 2 == 0)
		std::cout <<_target <<" has been robotomized successfully." <<std::endl;
	else
		std::cout <<"The robotomy failed." <<std::endl;
	i++;
}