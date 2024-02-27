#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		i;

	if (N < 0 || N > 100000)
		return NULL;
	horde = new Zombie[N];
	i = 0;
	while(i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return(horde);
}