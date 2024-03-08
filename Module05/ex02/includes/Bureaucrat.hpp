#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../includes/Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &rhs);

		Bureaucrat(std::string name, int grade);

		std::string getName();
		unsigned int getGrade();

		void increment();
		void decrement();

		void	signForm(Form form);

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