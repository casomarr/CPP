#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;

	public:
		Form();
		virtual ~Form();
		Form(Form const &copy);
		Form &operator=(Form const &rhs);

		Form(std::string name, int gradeToSign, int gradeToExecute);

		std::string getName();
		bool getIsSigned();
		unsigned int getGradeToSign();
		unsigned int getGradeToExecute();

		void	beSigned(Bureaucrat b);

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

std::ostream	&operator<<(std::ostream &output, Form &Form);