#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	public :
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
	protected :
	private :
};

//pas de IMateriaSource.cpp puisque tous = 0 sauf le destructeur mais il est déjà défini dans la classe. 
