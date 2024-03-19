#include "Bureaucrat.hpp"

int main()
{
	try //test for grade too high when decrementing
	{
		Bureaucrat charly("Charly", 150);
		std::cout <<charly;
		charly.increment();
		std::cout <<charly;
		charly.decrement();
		std::cout <<charly;
		charly.decrement();
		std::cout <<charly << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() <<std::endl; //std::cerr = std:::cout en sortie error
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl;
	}

	try //test grade too low in constructor
	{
		Bureaucrat samantha("Samantha", -10);
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() <<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl;
	}

	try //test grade too high in constructor
	{
		Bureaucrat summer("Summer", 151);
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() <<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() <<std::endl;
	}

	return 0;
}