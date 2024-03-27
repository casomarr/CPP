#pragma once

#include <iostream>
#include <string>

template <typename T> //il faut écrire ça au dessus de chaque fonction
void	swap(T &x, T &y) //& car on va les modifier sans les return
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T	min(T const &x, T const &y)
{
	return (x < y ? x : y); //CHECK norme
}

template <typename T>
T	max(T const &x, T const &y)
{
	return (x > y ? x : y); //CHECK norme
}