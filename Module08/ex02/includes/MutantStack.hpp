#pragma once

#include <stack>
#include <iostream>
#include <list>

/*
Some container types are actually adaptations of other containers. 
These are known as container adaptors. The three container adaptors 
provided by the STL library are std::stack, std::queue, and std::priority_queue.

When we say that one container is used as the "underlying container" for 
a container adaptor, we mean that the adaptor uses an instance of that 
container to store its elements and calls methods of that container.

std::vector<int> is the underlying container for std::stack. 
That means that a variable of type stack uses an std::vector<int> to 
store its elements and all its operations (push, pop, top, etc.) are 
implemented as stipulated in the container std::vector<int>.

Since our MutantStack class inherits from std::stack<T>, it uses 
std::deque<T> as its underlying container by default. To provide iterators, 
that happen to be available in std::deque but not in std::stack, we need to 
write the begin() and end() functions in our MutantStack class to be able to 
use the iterators in std::deque.
*/

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

		/*functions used in subject main :
		push, pop top and size already in std::stack
		.begin() and .end() need to be added*/

		/*ligne suivante pour eviter d'ecrire: "std::deque<T>::iterator begin()",
		ce qui est moins lisible*/
		typedef typename std::deque<T>::iterator iterator; //pour rappel: typedef est comme un define mais pour des types (je ne peux pas ecrire "iterator it;"" si iterator est un define)
		iterator begin()
		{
			return this->c.begin();
			/*c is a member of std::stack (also present in other 
			STL containers) that represents the underlying container. 
			So for std::stack, c is by default of type std::deque<T>*/
		}
		iterator end()
		{
			return this->c.end();

		}
};
