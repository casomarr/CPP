#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm() : _gradeToSign(145), _gradeToExecute(137), _target("Shrubbery form default name")
// {
// }

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Default Name")
{
	//IMPORTANT: if written as commented above instead, it is the values of AForm that will prevail
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) //GRAMMAR
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream file;
	std::string filename;

	filename = _target + "_shrubbery";
	file.open(filename.c_str(), std::ios::out); //"out" to write content ("in" to read)
	if (!file)
		throw std::runtime_error("Failed to open Shrubbery file"); /*IMPORTANT:
		we use runtime_error instead of an exception function because the file might exist
		and be accessible while the program is being tested and not be anymore at the time
		the program is actually run. It therefore describes more accurately the nature of
		the error.*/

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