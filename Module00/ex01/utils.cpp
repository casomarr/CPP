#include "amazingphonebook.h"
#include <cstdlib>

void	print_error()
{
	std::cout << "The only accepted options are \
	\"ADD\", \"SEARCH\" and \"EXIT\"" << std::endl;
}

bool	is_digits(const std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if (std::isdigit(str.c_str()[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

int	ask_index()
{
	std::string input;
	
	std::cout <<"Enter contact index to display : ";
	std::cin >> input; //only until first space (vs getline)
	std::cin.ignore(); //after std::cin to clear buffer so that no input is skipped but no need after getline
	if (is_digits(input) == true)
		return (atoi(input.c_str()));
	else
		return (-1);
}

bool	isValidString(std::string buffer)
{
	for (size_t i = 0; i < buffer.size(); i++)
	{
		if (!isgraph(buffer[i]) && !isspace(buffer[i]))
			return false;
	}
	return true;
}