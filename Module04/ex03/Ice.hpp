#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice &operator=(const Ice &other);
		AMateria* clone() const;
		void use(ICharacter& target);
};