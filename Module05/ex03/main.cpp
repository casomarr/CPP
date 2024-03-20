#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat samantha("Samantha", 30);
		Intern someRandomIntern;
		AForm* form1;

		//form created by intern
		form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		//form signed and executed by bureaucrat
		samantha.signForm(*form1);
		samantha.executeForm(*form1);

		delete form1;

		AForm* form2;
		form2 = someRandomIntern.makeForm("erroneous request", "Paul");
		samantha.signForm(*form2);
		samantha.executeForm(*form2);
		delete form2;
	}
	catch (Intern::FormNotFoundException &error)
	{
		std::cerr <<error.what() <<std::endl;
	}
	catch (AForm::GradeTooHighException &error) //IMPORTANT: AForm's exception
	{
		std::cerr << error.what() <<std::endl;
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
	}

	return 0;
}