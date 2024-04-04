#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	_numbers = other._numbers;
	_signs = other._signs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	_numbers = rhs._numbers;
	_signs = rhs._signs;
	return *this;
}

void RPN::check_valid_operation(std::string operation)
{
	unsigned int digit_nb = 0;
	unsigned int sign_nb = 0;

	//si pas un num && ...
	for (int i = 0; operation[i] != '\0'; i++)
	{
		if (std::isdigit(operation[i]) == 0 && operation[i] != '+' && \
		 operation[i] != '-' && operation[i] != '*' && operation[i] != '/' && operation[i] != ' ')
			throw std::runtime_error("Unvalid operation : wrong character");
		if (std::isdigit(operation[i]) != 0)
		{
			while(std::isdigit(operation[i]) != 0)
				i++;
			digit_nb ++;
		}
		if (operation[i] == '+' || operation[i] == '-' || \
		operation[i] == '*' || operation[i] == '/')
			sign_nb++;
	}
	if (sign_nb != digit_nb - 1)
		throw std::runtime_error("Unvalid operation : wrong number of digits and signs");
}

void RPN::reverse_polish_notation()
{
	int result;
	int first;
	int second;
	char sign;

	while(_numbers.size() > 1)
	{
			sign = _signs.top();
			_signs.pop();
			second = _numbers.top();
			_numbers.pop();
			first = _numbers.top();
			_numbers.pop();

			if (sign == '+')
			{
				result = first + second;
				std::cout <<first <<" + " <<second <<" = " <<result <<std::endl;
			}
			else if (sign == '-')
			{
				result = first - second;
				std::cout <<first <<" - " <<second <<" = " <<result <<std::endl;
			}
			else if (sign == '*')
			{
				result = first * second;
				std::cout <<first <<" * " <<second <<" = " <<result <<std::endl;
			}
			else if (sign == '/')
			{
				if (second == 0)
					throw std::runtime_error("Unvalid operation : division by 0");
				result = first / second;
				std::cout <<first <<" / " <<second <<" = " <<result <<std::endl;
			}
			else //SHOULD NEVER ARRIVE HERE
				throw std::runtime_error("Unvalid operation : wrong sign");
			
			_numbers.push(result);
	}
}

RPN::RPN(std::string operation)
{
	check_valid_operation(operation);

	std::string signs;

	int i = 0;
	while(operation[i] != '\0')
	{
		if (std::isdigit(operation[i]) != 0) //if is a number
			_numbers.push(operation[i] - '0'); //to convert char to int
		else if (operation[i] == '+' || operation[i] == '-' || \
		operation[i] == '*' || operation[i] == '/')
		{
			signs = "";
			while(signs.size() != _numbers.size() - 1 && operation[i] != '\0')
			{
				if (operation[i] == '+' || operation[i] == '-' || \
				operation[i] == '*' || operation[i] == '/')
					signs = signs + operation[i];
				if (std::isdigit(operation[i]) != 0) //if is a number
					throw std::runtime_error("Unvalid operation");
				i++;
			}
			int i = signs.size();
			while(i >= 0)
			{
				_signs.push(signs[i]);
				i--;
			}
			reverse_polish_notation();
			while(_signs.size() > 0)
				_signs.pop();
		}
		i++;
	}
	std::cout <<"Result = " <<_numbers.top() <<std::endl;
}
