#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class PresidentialPardonForm
{
	private:
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;
		std::string const _target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		PresidentialPardonForm(int gradeToSign, int gradeToExecute);

		PresidentialPardonForm(std::string target);
}