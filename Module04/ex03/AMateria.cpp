#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & copy)
{
	*this = copy;
}

AMateria & AMateria::operator=(AMateria const & other)
{
	_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	//TODO:
	(void)target; //pour compiler en attendant
}