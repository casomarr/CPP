#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*horde;
	std::string	name = "Lela";
	int	N = 5;

	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}