#include "Character.hpp"
#include "AMateria.hpp" //l'ordre compte!
#include "ICharacter.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
		// _inventory[i]->setType("");
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
	//doit delete les Materias du Character originel
	//(avant qu'elles oient remplacées par les Materias de copy)

	/* for (int i = 0; i < 4; i++)
	{
		_name = copy._name;
		if (_inventory[i] != NULL)
			delete _inventory[i];
	} */
	*this = copy;
}

Character & Character::operator=(Character const & other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL) //TODO: check
			delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	return *this;
}

Character::~Character()
{
	//delete Materias
/* 	for (int i = 0; i < 4; i++) //Materias already deleted in MateriaSource??
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	} */
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
	_inventory[idx] = NULL; //pas besoin de delete dans cette fonction 
}

void Character::use(int idx, ICharacter& target)
{
	//TODO: check
	if (idx >= 0 && idx <= 3 &&_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return _name;
}

//pour tests
void	Character::printInventory() const
{
	std::cout <<"Inventory :" <<std::endl;
	for(int i = 0; i< 4; i++)
	{
		if (_inventory[i] != NULL)
			std::cout <<_inventory[i]->getType() <<std::endl;
		else
			std::cout <<"NULL" <<std::endl;
	}
}