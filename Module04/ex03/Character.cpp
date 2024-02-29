#include "AMateria.hpp" //l'ordre compte!
#include "Character.hpp"
#include "Character.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i].type = "";
}

Character::Character(Character const & copy)
{
	//doit delete les Materias du Character originel
	//(avant qu'elles oient remplacées par les Materias de copy)
	for (int i = 0; i < 4, i++)
	{
		if (_inventory[i].type != "")
			delete _inventory[i];
	}
	*this = copy;
}

Character & Character::operator=(Character const & other)
{
	_type = other._type;
	return *this;
}

Character::~Character()
{
	//delete Materias
	for (int i = 0; i < 4, i++)
	{
		if (_inventory[i].type != "")
			delete _inventory[i];
	}
}

void Character::equip(AMateria* m) //pas ici car fx = 0 dans le .hpp
{
	for(int i = 0; i< 4; i++)
	{
		if (_inventory[i].type == "")
			_inventory[i] = m;
	}
}

void Character::unequip(int idx) //pas ici car fx = 0 dans le .hpp
{
	_inventory[idx] = ""; //pas le droit de delete dans cette fonction :
	//rajouter une variable privé qui enregistre l'adresse de la variable
	// qu'on unequip pour la delete dans une autre fonction
}

void Character::use(int idx, Character& target)
{
	//TODO:
	(void)idx;
	(void)target;
}

std::string const &Character::getName() const
{
	//TODO:
}

Character::Character(std::string name)
{
	_name = name;
}

//pour tests
void	Character::printInventory() const
{
	std::cout <<"Inventory :" <<std::endl;
	for(int i = 0; i< 4; i++)
		std::cout <<_inventory[i].type <<std::endl;
}