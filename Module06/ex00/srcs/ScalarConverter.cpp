#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

static bool is_number(std::string const &literal)
{
	int nb_of_signs = 0;
	int nb_of_comas = 0;
	unsigned long i = 0; //unsigned long instead of int because .length() returns an unisnged long so cannot be compared to an int
	while(literal[i])
	{
		if (std::isdigit(literal[i]) == 0 && literal[i] != '-' && literal[i] != '+' && literal[i] != '.') //if not a digit
		{
			if (i == (literal.length() - 1) && literal[i] == 'f')
				return true;
			return false;
		}
		if (literal[i] == '-' || literal[i] == '+')
			nb_of_signs	++;
		if (literal[i] == '.')
			nb_of_comas++;
		if (nb_of_signs > 1 || nb_of_comas > 1)
			return false;
		i++;
	}
	return true;
}

/* static_cast<new_type>(expression) */
void ScalarConverter::convert(std::string const &literal)
{
	//protections
	if (literal[0] == '\0')
	{
		std::cout <<"invalid input : empty string" <<std::endl;
		return ;
	}
	int i = 0;
	int nb_of_letters = 0;
	while (literal[i] != '\0')
	{
		if (std::isalnum(literal[i]) == 0 && literal[i] != '-' && literal[i] != '+' && literal[i] != '.') //if not all chars or digits
		{
			std::cout <<"Invalid input : " <<literal <<". Only characters and numbers accepted" <<std::endl;
			return ;
		}
		if (std::isalpha(literal[i]) != 0)
			nb_of_letters++;
		if (nb_of_letters > 1 && literal != "nan" && literal != "inf")
		{
			std::cout <<"invalid input : " <<literal <<". Only literals accepted (no multiple letters)" <<std::endl;
			return ;
		}
		i++;
	}

	if (std::isnan(std::atof(literal.c_str())) != 0) //nan
	{
		std::cout <<literal <<" to char: impossible" <<std::endl;
		std::cout <<literal <<" to int: impossible" <<std::endl;
		std::cout <<literal <<" to float: nanf" <<std::endl;
		std::cout <<literal <<" to double: nan" <<std::endl;
	}
	else if (std::isinf(std::atof(literal.c_str())) != 0) //inf
	{
		std::cout <<literal <<" to char: impossible" <<std::endl;
		std::cout <<literal <<" to int: infinite number" <<std::endl;
		std::cout <<literal <<" to float: infinite number" <<std::endl;
		std::cout <<literal <<" to double: infinite number" <<std::endl;
	}
	else if (is_number(literal) == true) //if is a digit
	{
		std::cout <<literal <<" to char: Non displayable" <<std::endl;
		if (std::atof(literal.c_str()) > INT_MAX || std::atof(literal.c_str()) < INT_MIN)
			std::cout <<literal <<" to int: Non displayable (overflow)" <<std::endl;
		else
			std::cout <<literal <<" to int: " <<std::atoi(literal.c_str()) <<std::endl;
		std::cout <<literal <<" to float: " <<std::atof(literal.c_str()) <<".0f" <<std::endl;
		std::cout <<literal <<" to double: " <<std::atof(literal.c_str()) <<".0" <<std::endl;
	}
	else if (literal.length() == 1)//not a digit (and therefore length should be of 1)
	{
		std::cout <<literal <<" to char: " <<static_cast<char>(literal[0]) <<std::endl;
		std::cout <<literal <<" to int: " <<static_cast<int>(literal[0]) <<std::endl;
		std::cout <<literal <<" to float: " <<static_cast<float>(literal[0]) <<".0f" <<std::endl;
		std::cout <<literal <<" to double: " <<static_cast<double>(literal[0]) <<".0" <<std::endl;
	}
	else
	{
		std::cout <<"invalid input" <<std::endl;
	}
}