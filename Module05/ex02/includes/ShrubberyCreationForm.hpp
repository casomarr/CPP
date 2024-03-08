#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class ShrubberyCreationForm
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

		ShrubberyCreationForm(std::string target);
}