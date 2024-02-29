#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice() : _type("ice")
{
}

Ice::Ice(Ice const & copy) : AMateria(copy) //!!!!
{
}

Ice & Ice::operator=(Ice const & other)
{
	_type = other._type;
	return *this;
}

Ice::~Ice()
{
}

std::string const & Ice::getType() const
{
	return _type;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout <<"* shoots an ice bolt at " <<target.getName() <<" *" <<std::endl;
}