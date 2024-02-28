#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called"<< std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = copy._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	WrongCat::makeSound()
{
	std::cout <<"Miaou!" <<std::endl;
}