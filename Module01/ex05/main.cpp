#include "Harl.hpp"
#include <bits/stdc++.h>

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout<< "Wrong number of arguments" <<std::endl;
		return (EXIT_FAILURE);
	}
	harl.complain(std::string(av[1]));
	return (EXIT_SUCCESS);
}