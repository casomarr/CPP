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

/* static_cast<new_type>(expression) */
void ScalarConverter::convert(std::string const &literal)
{
	//protections
	int i = 0;
	while (literal[i] != '\0')
	{
		if (std::isalnum(literal[i]) == 0) //if not all chars or digits
		{
			std::cout <<"Invalid input" <<std::endl;
			return ;
		}
		i++;
	}

	if (literal.length() == 0) //"" --> seulement \0 qui n'est pas compté
	{
		std::cout <<literal <<" to char: " <<std::endl;
		//verifier pour les trois en dessous : peut etre ne rien afficher plutôt que 0?
		std::cout <<literal <<" to int: 0" <<std::endl;
		std::cout <<literal <<" to float: 0.0f" <<std::endl;
		std::cout <<literal <<" to double: 0.0" <<std::endl;
	}
	else if (literal.length() == 1) //.length() does not count \0
	{
		if (std::isdigit(literal[0]) != 0) //if is a digit
		{
			std::cout <<literal <<" to char: Non displayable" <<std::endl;
			std::cout <<literal <<" to int: " <<literal[0] <<std::endl;
			std::cout <<literal <<" to float: " <<literal[0] <<".0f" <<std::endl;
			std::cout <<literal <<" to double: " <<literal[0] <<".0" <<std::endl;
		}
		else
		{
			std::cout <<literal <<" to char: " <<static_cast<char>(literal[0]) <<std::endl;
			std::cout <<literal <<" to int: " <<static_cast<int>(literal[0]) <<std::endl;
			std::cout <<literal <<" to float: " <<static_cast<float>(literal[0]) <<".0f" <<std::endl; //cast to int would be the same here
			std::cout <<literal <<" to double: " <<static_cast<double>(literal[0]) <<".0" <<std::endl; //cast to int would be the same here
		}
	}
	else
	{
		if (std::isnan(std::atof(literal.c_str())) != 0)
		{
			// std::cout <<"NAN" <<std::endl;
			std::cout <<literal <<" to char: impossible" <<std::endl;
			std::cout <<literal <<" to int: impossible" <<std::endl;
			std::cout <<literal <<" to float: nanf" <<std::endl;
			std::cout <<literal <<" to double: nan" <<std::endl;
		}
		else if (std::isinf(std::atof(literal.c_str())) != 0)
		{
			// std::cout <<"INF" <<std::endl;
			std::cout <<literal <<" to char: impossible" <<std::endl;
			std::cout <<literal <<" to int: infinite number" <<std::endl;
			std::cout <<literal <<" to float: infinite number" <<std::endl;
			std::cout <<literal <<" to double: infinite number" <<std::endl;
		}
		else
		{
			// std::cout <<"DIGIT" <<std::endl;
			std::cout <<literal <<" to char: Non displayable" <<std::endl;
			std::cout <<literal <<" to int: " <<std::atoi(literal.c_str()) <<std::endl;
			std::cout <<literal <<" to float: " <<std::atof(literal.c_str()) <<".0f" <<std::endl;
			std::cout <<literal <<" to double: " <<std::atof(literal.c_str()) <<".0" <<std::endl;
		}
	}

}