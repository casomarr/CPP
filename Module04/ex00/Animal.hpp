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
		// virtual void	makeSound() = 0; // rend la classe abstraite et permet de ne pas declarer la fonction dans Animal.cpp vu que doit rester vide 
		virtual void	makeSound();
		std::string	getType();
	protected :
		std::string	_type;
	private :
};

#endif