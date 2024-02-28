#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Default AAnimal constructor called"<< std::endl;
	_type = "Unspecified AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	_type = copy._type;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout <<"Unspecified animal sound" <<std::endl;
}

const std::string	AAnimal::getType() const
{
	return _type;
}