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
	std::cout << "Animal destroyer called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}