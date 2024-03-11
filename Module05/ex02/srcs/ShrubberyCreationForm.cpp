#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : _gradeToSign(0), _gradeToExecute(0), _target("")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _target(copy._target)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(int gradeToSign, int gradeToExecute): _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 145)
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (gradeToExecute > 137)
		throw ShrubberyCreationForm::GradeTooLowException();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() < this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream file;
	std::string filename;

	filename = _target + "_shrubbery";
	file.open(filename.c_str(), std::ios::out); //"out" to write content ("in" to read)
	if (!file)
		throw std::runtime_error("Failed to open Shrubbery file"); //CHECK (adapter main?) //garder std::runtime error???

	file << "                      %%%,%%%%%%%" <<std::endl;
	file << "                   ,'%% \\-*%%%%%%%" <<std::endl;
	file << "             ;%%%%%*%   _%%%%" <<std::endl;
	file << "              ,%%%       \\(_.*%%%%." <<std::endl;
	file << "              % *%%, ,%%%%*(    '" <<std::endl;
	file << "            %^     ,*%%% )\\|,%%*%,_" <<std::endl;
	file << "                 *%    \\/ #).-*%%*" <<std::endl;
	file << "                     _.) ,/ *%," <<std::endl;
	file << "             _________/)#(_______" <<std::endl;
	file.close();
}
