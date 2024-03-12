#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../includes/AForm.hpp"

// class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		// unsigned int const _gradeToSign;
		// unsigned int const _gradeToExecute;
		std::string const _target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		// RobotomyRequestForm(int gradeToSign, int gradeToExecute);
		RobotomyRequestForm(std::string &target);

		void execute(Bureaucrat const & executor) const;
}; //IMPORTANT: error: new types may not be defined in a return type --> oublié le ; à la fin de la classe