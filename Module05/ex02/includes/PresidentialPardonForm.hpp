#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../includes/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		PresidentialPardonForm(const std::string &target);
		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};