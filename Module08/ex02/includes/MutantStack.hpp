#pragma once

#include <stack>
#include <iostream>
#include <list>

/*
In the C++ Standard Library, some container types are actually not containers themselves, 
but are adaptations of other containers. These are known as container adaptors. 
The three container adaptors provided by the library are std::stack, std::queue, and std::priority_queue.

When we say that one container is used as the "underlying container" for a container adaptor, 
we mean that the adaptor uses an instance of that container to store its elements and implements its 
own interface by calling methods on that container.

For example, std::stack is a container adaptor that provides a restricted interface to its underlying container. 
By default, std::stack uses std::deque as its underlying container, but you can specify a different container 
type when you declare a std::stack.

Here's an example:

In this case, std::vector<int> is the underlying container for std::stack. 
The stack s will use a std::vector<int> to store its elements. All stack operations (push, pop, top, etc.) 
will be implemented in terms of corresponding operations on the std::vector<int>.

In your MutantStack class, you're inheriting from std::stack<T>, so std::stack<T> is using std::deque<T> as 
its underlying container by default. You're then providing additional functionality (like iterators) that 
aren't available in std::stack but are available in std::deque.
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