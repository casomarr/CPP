#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal constructor called"<< std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
		*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<this->_type << " destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout <<"Wrong animal sound" <<std::endl;
}

const std::string	WrongAnimal::getType() const
{
	return _type;
}