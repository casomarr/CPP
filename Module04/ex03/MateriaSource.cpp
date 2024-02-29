#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	*this = copy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	_type = other._type;
	return *this;
}

MateriaSource::~MateriaSource()
{
}

AMateria*	createMateria(std::string const & type)
{
	//TODO:
}

void		learnMateria(AMateria*)
{
	//TODO:
}