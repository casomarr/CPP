#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called"<< std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = copy._type;
}

Dog::~Dog()
{
	std::cout << "Dog destroyer called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}