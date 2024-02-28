#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &other);
	protected:
		std::string _ideas[100]; //ici ou en public? prive?
	private:
};

#endif