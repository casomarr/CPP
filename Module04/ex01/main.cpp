#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
//----------------------- MAIN TESTS -----------------------

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

//----------------------- PERSONAL TESTS -----------------------

	/* //create animal array with cats and dogs
	int arraySize = 6;
	const Animal *animal[arraySize];
	int i = 0;

	if (arraySize <= 0)
		return 1;

	while(i < arraySize)
	{
		animal[i] = new Cat();
		if (i + 1 < arraySize)
		{
			animal[i + 1] = new Dog();
			i++;
		}
		i++;
	}

	//print array
	std::cout <<std::endl;
	i = 0;
	while(i < arraySize)
	{
		std::cout <<"animal of type " << animal[i]->getType() <<" makes ";
		animal[i]->makeSound();
		i++;
	}
	
	//delete array
	std::cout <<std::endl;
	i = 0;
	while(i < arraySize)
	{
		delete animal[i];
		i++;
	} */


//----------------------- DEEP COPY TEST -----------------------

/* 	//copy constructor
	Dog *src = new Dog();
	Dog *copy = new Dog(*src);
	delete src;
	std::cout <<"-----" <<copy->getType() <<"-----" <<std::endl;
	delete copy;

	//= operator
	Dog basic;
	{
		Dog tmp = basic;
	} */

	return 0;
}