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
	*this = copy;

/* 	//DEEP COPY
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (copy._inventory[i] != NULL)
			_inventory[i] = copy._inventory[i]->clone(); //deep copy
		else
			_inventory[i] = NULL;
	} */
}

Character & Character::operator=(Character const & other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	return *this;

	/* //DEEP COPY
	if (this != &other) {
		// First, delete any existing materia in this inventory
		for (int i = 0; i < 4; i++) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL; // Avoid dangling pointers
		}
		// Then clone the materia from the other character
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i] != NULL) {
				this->_inventory[i] = other._inventory[i]->clone();
			}
		}
	} */
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	std::cout <<"Character destructor" <<std::endl;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i< 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 &&_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else if (_inventory[idx] == NULL)
		std::cout <<"No materia in this slot" <<std::endl;
	else
		std::cout <<"Invalid index" <<std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}
