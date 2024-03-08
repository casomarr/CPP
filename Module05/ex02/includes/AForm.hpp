#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;

	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &copy);
		AForm &operator=(AForm const &rhs);

		AForm(std::string name, int gradeToSign, int gradeToExecute);

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

std::ostream	&operator<<(std::ostream &output, AForm &AForm);