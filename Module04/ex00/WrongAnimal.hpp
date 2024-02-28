#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		/* virtual  */~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);
		/* virtual  */void	makeSound();
		std::string	getType();
	protected :
		std::string	_type;
	private :
};

#endif