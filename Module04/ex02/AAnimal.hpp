#ifndef	AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public :
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal(); //to be able to delete cat and dog
		AAnimal &operator=(const AAnimal &other);
		virtual void	makeSound() const = 0; // rend la classe abstraite et permet de ne pas declarer la fonction dans Animal.cpp vu que doit rester vide 
		const std::string	getType() const;
	protected :
		std::string	_type;
	private :
};

#endif