#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string nameB) : name(nameB)
{
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weaponB)
{
	weapon = &weaponB;
}

void	HumanB::attack()
{
	std::cout <<name <<" attacks with their " <<weapon->getType() <<std::endl;
}