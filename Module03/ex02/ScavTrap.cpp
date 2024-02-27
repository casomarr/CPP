#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "SvapTrap Constructor called for " << name << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Copy constructor called for " << copy._name << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SvapTrap Destroyer called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignation operator called for " << other._name << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;

}

/*Makes ScavTrap to lose 1 energy point for making the attack action*/
void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout <<_name <<" has no energy points left to attack" <<std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout <<_name <<" is dead and therefore cannot attack" <<std::endl;
		return ;
	}
	std::cout <<"ScavTrap " << _name <<" attacks " <<target <<", causing " <<_attackDamage << " points of damage!" <<std::endl;
	_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
	{
		std::cout <<_name <<" is dead and therefore cannot enter Gate keeper mode" <<std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}