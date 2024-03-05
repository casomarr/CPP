#ifndef	CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream>
#include "AAnimal.hpp"

class Cat : public AAnimal
{
	public :
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &other);
		void	makeSound() const;
	private :
		Brain *brain;
};

#endif