#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> /*"La classe sera implémentée en termes de la
std::stack. Elle offrira toutes ses fonctions membres avec en plus des itérateurs"*/
{
	private :
		std::stack<T> _stack;
	public:
		MutantStack() {};
		MutantStack(MutantStack const &other)
		{
			*this = other;
		};
		MutantStack &operator=(MutantStack const &other)
		{
			_stack = other._stack;
			return *this;
		};
		~MutantStack() {};

		//push, pop top and size already in std::stack

		//rajouter iterateurs : begin and end to be added
/*		typename std::stack<T>::iterator iterator;
		typename std::stack<T> begin()
		{
			return _stack.begin();
		};
*/


/*		T &operator[](size_t index) //necessaire? de l'ex02 du module7
		{
			if (index >= size())
				throw std::out_of_range("Index out of array range");
			return _stack[index];
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return _stack[0];
		};
*/
		/*ligne suivante pour eviter d'ecrire: "std::deque<T>::iterator begin()",
		ce qui est moins lisible*/
		typedef typename std::deque<T>::iterator iterator; //pour rappel: typedef est comme un define mais pour des types (je ne peux pas ecrire "iterator it;"" si iterator est un define)
		iterator begin()
		{
			return this->c.begin();
			/*this->c refers to the member c of the current object. 
			c is a member of std::stack and other STL containers that 
			represents the underlying container. In the case of std::stack, 
			c is by default of type std::deque<T>*/
		}
		iterator end()
		{
			return this->c.end();

		}



};