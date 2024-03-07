#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat charly("Charly", 10);
		std::cout <<charly;	//test increementation and decrementation
		charly.increment();
		std::cout <<charly;
		charly.decrement();
		std::cout <<charly << std::endl;
		//test grade too high
		Bureaucrat samantha("Samantha", 0);
		//test grade too low
		Bureaucrat summer("Summer", 151);
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