#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called"<< std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called for " << name << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called for " << copy._name << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroyer called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignation operator called for " << other._name << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

/*Makes ClapTrap to lose 1 energy point for making the attack action*/
void	ClapTrap::attack(const std::string &target)
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
	std::cout << _name << " attacks " << target <<", causing " <<_attackDamage << " points of damage!" <<std::endl;
	_energyPoints -= 1;
}

/*Makes ClapTrap to lose the amount sent in parameters to its _hitPoints*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout <<_name <<" is dead and therefore cannot take more damages" <<std::endl;
		return ;
	}
	//std::cout << "The attack cost " <<amount << " life points!" <<std::endl;
	_hitPoints -= amount;
}

/*Makes ClapTrap to regaing the amount sent in parameters to 
its _hitPoints and lose 1 energy point for doing the repair action*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout <<_name <<" has no energy points left to repair itself" <<std::endl;
		return ;
	}
	std::cout << _name << " is repaired, getting " <<amount \
	<<" live points back!" <<std::endl;
	_hitPoints += amount;
	_energyPoints -= 1;
}

void	ClapTrap::setAttackDammages(unsigned int amount)
{
	_attackDamage = amount;
}

unsigned int	ClapTrap::getAttackDammages()
{
	return _attackDamage;
}

unsigned int	ClapTrap::getHitPoints()
{
	return _hitPoints;
}