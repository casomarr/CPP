#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"

int main()
{
	/* try
	{
		std::cout << std::endl;
		Bureaucrat samantha("Samantha", 30);
		std::cout <<samantha << std::endl;

		AForm *sform = new ShrubberyCreationForm();
		std::cout << *sform;
		AForm *rform = new RobotomyRequestForm();
		std::cout << *rform;
		AForm *pform = new PresidentialPardonForm();
		std::cout << *pform << std::endl;

		samantha.signForm(*sform);
		samantha.signForm(*rform);
		samantha.signForm(*pform);
		std::cout << std::endl;

		samantha.executeForm(*sform);
		samantha.executeForm(*rform);
		samantha.executeForm(*pform);
		std::cout << std::endl;

		delete sform;
		delete rform;
		delete pform;

		Bureaucrat samuel("Samuel", 300);
	}
	catch (AForm::GradeTooHighException &error)  //IMPORTANT: AForm's exception
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	catch (AForm::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl;
	}
	catch (AForm::NotSignedException &error)
	{
		std::cerr << error.what() <<std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &error) //IMPORTANT: Bureaucrat's exception
	{
		std::cerr << error.what() <<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl;
	} */



	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	return 0;
}