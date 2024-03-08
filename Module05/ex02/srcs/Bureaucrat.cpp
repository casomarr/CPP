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

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	_grade = grade;
	if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High : shouldn't exceed 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low : shouldn't be under 1");
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

void	Bureaucrat::signForm(Form form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout <<this->getName() <<" could not sign " <<form.getName() <<" because " <<e.what() <<std::endl;
	}
	if (form.getIsSigned() == true)
		std::cout <<this->getName() <<" signed " <<form.getName() <<std::endl;
	
}

std::ostream	&operator<<(std::ostream &output, Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<std::endl;
	return (output);
}