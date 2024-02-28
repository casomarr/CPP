#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called"<< std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy._type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	Cat::makeSound()
{
	std::cout <<"Miaou!" <<std::endl;
}