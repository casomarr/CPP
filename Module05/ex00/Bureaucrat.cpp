#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	_grade = rhs._grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) //IMPORTANT declarer ici et non dans la fonction car const string
{
	_grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException(); //throw dans .hpp et .cpp, try et catch dans le main
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat's grade is too high (shouldn't exceed 150)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat's grade is too low (shouldn't be under 1)");
}

std::string Bureaucrat::getName()
{
	return _name;
}

unsigned int Bureaucrat::getGrade()
{
	return _grade;
}

void Bureaucrat::increment()
{
	_grade+=1;
}

void Bureaucrat::decrement()
{
	_grade-=1;
}

std::ostream	&operator<<(std::ostream &output, Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<std::endl;
	return (output);
}