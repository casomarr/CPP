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

/* 		AForm *sform = new ShrubberyCreationForm(); //constructors with default AForm's name
		std::cout << *sform;
		AForm *rform = new RobotomyRequestForm();
		std::cout << *rform;
		AForm *pform = new PresidentialPardonForm();
		std::cout << *pform << std::endl; */

//HERE: EN TRAIN D ENLEVER LES NEW POUR NE PAS AVOIR DE LEAKS DU AU FAIT QUE DES QU EXCEPTION EST CATCH ON NE CONTINUE PAS DANS LE MAIN DONC PAS DE DELETE
		ShrubberyCreationForm *sform(); //constructors with default AForm's name
		std::cout << sform;
		RobotomyRequestForm *rform();
		std::cout << rform;
		PresidentialPardonForm *pform();
		std::cout << pform << std::endl;

		samantha.signForm(*sform);
		samantha.signForm(*rform);
		//grade too low to sign : exception printed
		samantha.signForm(*pform);
		std::cout << std::endl;

		//grade ok to execute : nothing is printed
		samantha.executeForm(*sform);
		//to test execution robotomy 50% of the time
		samantha.executeForm(*rform);
		samantha.executeForm(*rform);
		//----------------------------------
		//grade too low to execute : exception printed
		samantha.executeForm(*pform);
		std::cout << std::endl;

		//To check that we can also call constructors with specified name
		// Bureaucrat paul("Paul", 2);
		Bureaucrat paul("Paul", 300); //FIX: cette ligne a la place de celle du dessus cree des leaks //HERE
		std::cout <<paul;
		//"Leila" will appear in the printed message
		PresidentialPardonForm presidentialForm("Leila");
		paul.signForm(presidentialForm);
		paul.executeForm(presidentialForm);
		//"Thibault" will appear in the created file name
		ShrubberyCreationForm shrubberyform("Thibault");
		paul.signForm(shrubberyform);
		paul.executeForm(shrubberyform);

		// delete sform;
		// delete rform;
		// delete pform;
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

