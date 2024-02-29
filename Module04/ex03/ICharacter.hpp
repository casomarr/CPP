#include "AMateria.hpp" //en dehors de pragma once!!!
#pragma once

#include <iostream>
#include <string>

class AMateria; //Nécessaire?

class ICharacter
{
	public :
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected :
		std::string	_name;
	private :
};

//pas de Icharacter.cpp puisque tous = 0 sauf le destructeur mais il est déjà défini dans la classe. 