#pragma once

#include <iostream>
#include <string>

template <typename T>
void	print_elements(T const *element)
{
	std::cout <<*element <<" ";
}

template <typename T>
void	iter(T *array, size_t length, void (*func)(T const *element))
{
	std::cout <<"Array address : " <<array <<std::endl;
	std::cout <<"Array length : " <<length <<std::endl;
	std::cout <<"Array elements: ";
	for (size_t i = 0; i < length; i++)
		func(&array[i]);
	std::cout <<std::endl;
}

//STL library : librairie de templates et conteneurs