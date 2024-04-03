#pragma once 

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
		void addNumber(int start, int end, unsigned int length);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};