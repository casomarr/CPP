#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

#include "Zombie.hpp"
void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main()
{
	Zombie *zombie;

	zombie = newZombie("Heap");
	zombie->announce();
	delete zombie;

	randomChump("Stack");

	return (0);
}