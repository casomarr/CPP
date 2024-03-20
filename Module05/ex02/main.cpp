#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		std::cout << std::endl;
		Bureaucrat samantha("Samantha", 30);
		std::cout <<samantha << std::endl;

		ShrubberyCreationForm sform; //constructors with default AForm's name
		std::cout << sform;
		RobotomyRequestForm rform;
		std::cout << rform;
		PresidentialPardonForm pform;
		std::cout << pform << std::endl;

		samantha.signForm(sform);
		samantha.signForm(rform);
		//grade too low to sign : exception printed
		samantha.signForm(pform);
		std::cout << std::endl;

		//grade ok to execute : nothing is printed
		samantha.executeForm(sform);
		//to test execution robotomy 50% of the time
		samantha.executeForm(rform);
		samantha.executeForm(rform);
		//----------------------------------
		//grade too low to execute : exception printed
		samantha.executeForm(pform);
		std::cout << std::endl;

		//To check that we can also call constructors with specified name
		Bureaucrat paul("Paul", 2);
		std::cout <<paul;
		//"Leila" will appear in the printed message
		PresidentialPardonForm presidentialForm("Leila");
		paul.signForm(presidentialForm);
		paul.executeForm(presidentialForm);
		//"Thibault" will appear in the created file name
		ShrubberyCreationForm shrubberyform("Thibault");
		paul.signForm(shrubberyform);
		paul.executeForm(shrubberyform);
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

