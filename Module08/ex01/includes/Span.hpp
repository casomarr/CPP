#pragma once 

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

class Span
{
	private :
		std::vector<int> _list;
		unsigned int _max_nb;
	public :
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int nb);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};