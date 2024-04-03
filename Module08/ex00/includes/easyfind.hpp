#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
/*std::vector has several advantages over arrays :
- dynamic size : you can use the already integrated
functions like push_back() , insert(), erase()...
that will automatically handle its size.
- safety : if trying to access an element out of bounds,
it will throw an exception.*/
typename T::iterator easyfind(T &list, int nb)
{
	if (list.empty())
		throw std::runtime_error("The list is empty");

	typename T::iterator ptr = std::find(list.begin(), list.end(), nb);
	if (ptr == list.end())
		throw std::runtime_error("Nb not found");

	return (ptr);
}
