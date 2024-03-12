#include "../includes/Intern.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(Intern const &copy)
{
	*this = copy;
}
Intern &Intern::operator=(Intern const rhs)
{
	//TODO ???? puisque pas d attributs prives
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	//HERE
	AForm *forms;
	forms[0] = ShrubberyCreationForm();
	forms[1] = RobotomyRequestForm();
	forms[2] = PresidentialPardonForm();

	


}


