#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(Cure const & copy) : AMateria("cure")
{
	*this = copy;
}

Cure & Cure::operator=(Cure const & other)
{
	_type = other._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout <<"* heals " <<target.getName() <<"'s wounds "<<std::endl;
}