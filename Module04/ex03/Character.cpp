#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout <<"Character default constructor" <<std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout <<"Character constructor with name" <<std::endl;
}

Character::Character(Character const & copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character & Character::operator=(Character const & other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	std::cout <<"Character destructor" <<std::endl;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout <<"Inventory is full" <<std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else if ((idx >= 0 && idx <= 3) && _inventory[idx] == NULL)
		std::cout <<"No materia in this slot" <<std::endl;
	else
		std::cout <<"Invalid index" <<std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}

AMateria	*Character::getMateria(int index)
{
	return _inventory[index];
}