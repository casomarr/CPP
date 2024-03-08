#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form form("Boring Form", 14, 17);
		std::cout <<form <<std::endl;;


		Bureaucrat samantha("Samantha", 10);
		std::cout <<samantha;
		samantha.signForm(form);
		std::cout << std::endl;


		Bureaucrat charly("Charly", 70);
		std::cout <<charly;
		charly.signForm(form);
		std::cout << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	return 0;
}