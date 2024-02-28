#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called"<< std::endl;
	_type = "Unspecified Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_type = copy._type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	Animal::makeSound()
{
	std::cout <<"Unspecified animal sound" <<std::endl;
}

std::string	Animal::getType()
{
	return _type;
}