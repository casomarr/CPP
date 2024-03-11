#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../includes/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;
		std::string const _target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		ShrubberyCreationForm(int gradeToSign, int gradeToExecute);

		void execute(Bureaucrat const & executor) const;
};