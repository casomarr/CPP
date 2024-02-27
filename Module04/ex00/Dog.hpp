#ifndef	DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &other);
	protected :
	private :
		std::string	_type; //ici?
}

#endif