#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materias[i])
			_materias[i] = copy._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL)
		{
			delete _materias[i];
			_materias[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++ )
		if ( _materias[i] && _materias[i]->getType() == type )
			return _materias[i]->clone();
	return NULL;
}

void	MateriaSource::learnMateria(AMateria* materiaToLearn)
{
	if (!materiaToLearn)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = materiaToLearn;
			return;
		}
	}
	delete materiaToLearn;
}

AMateria* MateriaSource::getMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i];
	return NULL;
}