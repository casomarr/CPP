#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>

class ScalarConverter
{
	private:
		//must not be instanciable by users
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &rhs);

	public:
		~ScalarConverter();

		static void convert(std::string const &literal); //GRAMMAR: "static" dans .hpp mais pas dans .cpp


};

// explications des differents types de cast :
// https://github.com/aoumad/CPP_Modules/tree/main/Module_06
// bon exemple:
// https://github.com/pasqualerossi/C-Plus-Plus/tree/main/C%2B%2B%20Module%2006/ex00