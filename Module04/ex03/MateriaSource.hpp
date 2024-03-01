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
		void		learnMateria(AMateria* materiaToLearn); //ais-je le droit de rajouter un nom de variable?
		AMateria*	getMateria( std::string const & type ); //check sujet si nécessaire
	protected :
	private :
		 AMateria*	_materias[4];
};