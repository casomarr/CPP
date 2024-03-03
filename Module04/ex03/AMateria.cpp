#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("")
{
	std::cout << "Default AMateria constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor with type" << std::endl;
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
	std::cout << "AMateria destructor" << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}