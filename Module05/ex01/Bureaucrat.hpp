#pragma once

#include <string>
#include <iostream>
#include <exception> //IMPORTANT
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;

	public:
		//GRAMMAR : les 4 de forme canonique sont du type de la classe (operator n'est pas void!!)
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy); //GRAMMAR
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