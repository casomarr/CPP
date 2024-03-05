#ifndef	DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	public :
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &other);
		void	makeSound() const;
	private :
		Brain *brain;
};

#endif