#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string weapon)
{
	type = weapon;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType()
{
	return(type);
}

void	Weapon::setType(std::string value)
{
	type = value;
}