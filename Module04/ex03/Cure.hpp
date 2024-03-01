#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure &copy);
		virtual ~Cure();
		Cure &operator=(const Cure &other);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
	protected :
		// std::string _type;
	private :
};
