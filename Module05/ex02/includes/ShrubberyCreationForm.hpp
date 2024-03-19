#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../includes/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		ShrubberyCreationForm(const std::string &target);
		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};