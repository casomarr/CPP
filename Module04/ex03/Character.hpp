#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character(std::string name);
		Character(Character const & copy);
		Character & operator=(Character const & other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, Character& target);
		
		//pour tests
		void	printInventory() const;
	protected :
		AMateria *_inventory[4];
		std::string _name;
	private :
};