#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap Constructor called for " << name << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "Copy constructor called for " << copy._name << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destroyer called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignation operator called for " << other._name << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;

}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " asks for a high five" << std::endl;
}