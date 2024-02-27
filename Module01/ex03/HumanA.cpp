#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string nameA, Weapon &weaponA) : weapon(weaponA), name(nameA)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout <<name <<" attacks with their " <<weapon.getType() <<std::endl;
}