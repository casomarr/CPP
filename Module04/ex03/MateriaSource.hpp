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
		void		learnMateria(AMateria* materiaToLearn);
		AMateria*	getMateria( std::string const & type );
	protected :
	private :
		 AMateria*	_materias[4];
};