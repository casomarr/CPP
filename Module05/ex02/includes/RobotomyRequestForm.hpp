#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../includes/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		RobotomyRequestForm(std::string &target);
		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
}; //IMPORTANT: "error: new types may not be defined in a return type" --> oublié le ; à la fin de la classe