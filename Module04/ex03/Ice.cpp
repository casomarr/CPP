#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(Ice const & copy) : AMateria(copy)
{
	(void)copy;
}

Ice & Ice::operator=(Ice const & other)
{
	(void)other;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use( ICharacter& target ) 
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}