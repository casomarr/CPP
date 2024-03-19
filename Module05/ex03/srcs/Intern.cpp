#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

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
Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs; //puisque pas d attributs prives
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	/* AForm *forms = NULL;
	forms[0] = new ShrubberyCreationForm(formTarget);
	forms[1] = new RobotomyRequestForm(formTarget);
	forms[2] = new PresidentialPardonForm(formTarget); */

	AForm *forms[] = { //GRAMMAR : la version au dessus ne marche pas car = ne peut pas marcher entre AForm et une class de form different
	new ShrubberyCreationForm(formTarget),
	new RobotomyRequestForm(formTarget),
	new PresidentialPardonForm(formTarget)
	};

	std::string formNamesArray[] = { //forms[0] = x ne marche pas car comme on ne malloc pas avant il faut initialier direct
	"shrubbery request",
	"robotomy request",
	"presidential request"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNamesArray[i])
		{
			AForm* ret = forms[i];
			std::cout <<"Intern creates " <<formName <<std::endl;
			for (int j = 0; j < 3; j++) //IMPORTANT car sinon on return qu'une seule instance de l'array et dans le main on ne peut supprimer que cette derniere donc les autres se perdent
			{
				if (i != j)
					delete forms[j];
			}
			return ret;
		}
	}
	for (int i = 0; i < 3; i++) //IMPORTANT idem que en aut: doit se supprimer car pas returned dans le main
		delete forms[i];
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("The intern could not create the form because it was not found.");
}