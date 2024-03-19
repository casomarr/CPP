#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../includes/AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int/*  const */ _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &rhs);

		Bureaucrat(std::string name, int grade);

		std::string getName() const;
		unsigned int getGrade() const;

		void increment();
		void decrement();

		void	signForm(AForm &form);
		void	executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &output, Bureaucrat &bureaucrat);