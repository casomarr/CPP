#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name_arg)
{
	name = name_arg;
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called for Zombie called " <<this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout <<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
