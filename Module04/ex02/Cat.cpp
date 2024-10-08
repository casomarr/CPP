#include "Cat.hpp"
#include "AAnimal.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called"<< std::endl;
	_type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy._type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	_type = other._type;
	brain = new Brain(*other.brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout <<"Miaou!" <<std::endl;
}