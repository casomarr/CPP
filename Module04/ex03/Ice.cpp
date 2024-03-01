#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Ice::Ice() : _type("ice")
// {
// }

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(Ice const & copy) : AMateria(copy) //!!!!
{
	*this = copy;
}

Ice & Ice::operator=(Ice const & other)
{
	_type = other._type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

/* std::string const & Ice::getType() const
{
	return _type;
} */

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	//TODO: check if print needed
	std::cout <<"* shoots an ice bolt at " <<target.getName() <<" *" <<std::endl;
}