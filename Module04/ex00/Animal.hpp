#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public :
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal(); //to be able to delete cat and dog
		Animal &operator=(const Animal &other);
		virtual void	makeSound() const;
		const std::string	getType() const;
	protected :
		std::string	_type;
};

#endif