#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public :
		Animal();
		Animal(const Animal &copy);
		~Animal();
		Animal &operator=(const Animal &other);
		void	makeSound();
	protected :
		std::string	_type;
	private :
}

#endif