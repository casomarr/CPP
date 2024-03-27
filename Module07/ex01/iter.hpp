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

//video specialization https://elearning.intra.42.fr/notions/piscine-c-d07-templates/subnotions/piscine-c-d07-templates-specialization/videos/cpp_bootcamp_-_d07_-_03_specialization
//min 12:20
//STL library : librairie de templates et conteneurs