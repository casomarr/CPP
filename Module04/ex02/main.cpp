#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	//create animal array with cats and dogs
	int arraySize = 10;
	const AAnimal *animal[arraySize];
	int i = 0;
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
	}
	//delete animal;

	return 0;
}