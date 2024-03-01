#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter; //Nécessaire?

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		AMateria & operator=(AMateria const & other);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		// void setType(std::string type); //en plus
	protected:
		std::string _type;
};