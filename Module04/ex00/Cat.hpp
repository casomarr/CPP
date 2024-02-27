#ifndef	CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream>

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &other);
	protected :
	private :
		std::string	_type; //ici?
}

#endif