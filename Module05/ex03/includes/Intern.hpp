#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

class Intern : public Bureaucrat
{
	public :
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const rhs);

		//Malgr'e l'exemple dans le sujet c est bien AForm!
		AForm*	makeForm(std::string formName, std::string formTarget);
}