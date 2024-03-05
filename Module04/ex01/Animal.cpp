#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called"<< std::endl;
	_type = "Unspecified Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
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

void	Animal::makeSound() const
{
	std::cout <<"Unspecified animal sound" <<std::endl;
}

const std::string	Animal::getType() const
{
	return _type;
}