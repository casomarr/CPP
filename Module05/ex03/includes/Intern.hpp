#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

class Intern : public Bureaucrat
{
	public :
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &rhs);

		AForm*	makeForm(std::string formName, std::string formTarget);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};