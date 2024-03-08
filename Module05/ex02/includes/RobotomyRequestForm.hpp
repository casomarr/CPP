#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class RobotomyRequestForm
{
	private:
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;
		std::string const _target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		RobotomyRequestForm(int gradeToSign, int gradeToExecute);

		RobotomyRequestForm(std::string target);
}