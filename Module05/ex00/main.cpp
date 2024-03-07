#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *charly;
	try
	{
		charly = new Bureaucrat("Charly", 150);
		charly->increment();
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	std::cout <<charly->getName() <<"'s grade is " <<charly->getGrade() <<"!" <<std::endl;

	return 0;
}