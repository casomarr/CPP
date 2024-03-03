#pragma once
// #include "AMateria.hpp"

#include <iostream>
#include <string>

class AMateria;

/* Interface classes don't get a corresponfing .cpp
file since all their functions are purely virtual 
(they end with "= 0" when declared) */
class ICharacter
{
	public :
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected :
	private :
};