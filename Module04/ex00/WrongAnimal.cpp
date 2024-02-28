#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal constructor called"<< std::endl;
	_type = "Unspecified WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = copy._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	WrongAnimal::makeSound()
{
	std::cout <<"Wrong animal sound" <<std::endl;
}

std::string	WrongAnimal::getType()
{
	return _type;
}