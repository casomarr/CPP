#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned = false;
		unsigned int const _gradeToSign = 0;
		unsigned int const _gradeToExecute = 0;

	public:
		Form();
		~Form();
		Form(Form const &copy);
		Form &operator=(Form const &rhs);

		Form(std::string name, int gradeToExecute, int gradeToSign);

		std::string getName();
		unsigned int getGrade();
		unsigned int getGradeToSign();
		unsigned int getGradeToExecute();
		bool getIsSigned();


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