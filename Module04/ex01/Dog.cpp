#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called"<< std::endl;
	_type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = copy._type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout <<"Waf!" <<std::endl;
}