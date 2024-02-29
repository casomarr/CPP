#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : _type("cure")
{
}

Cure::Cure(Cure const & copy) : AMateria(copy)
{
}

Cure & Cure::operator=(Cure const & other)
{
	_type = other._type;
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout <<"* heals " <<target.getName() <<"'s wounds "<<std::endl;

}