#pragma once

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource &operator=(MateriaSource const &other);
		~MateriaSource();

		AMateria*	createMateria(std::string const & type);
		void		learnMateria(AMateria*);
	protected :
	private :
};