#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	// Dog *dog = new Dog();
	// Cat *cat = new Cat();

	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	std::cout <<std::endl;

	std::cout <<"dog type : " <<dog->getType() << std::endl;
	std::cout <<"cat type : "<<cat->getType() << std::endl;
	std::cout <<std::endl;

	std::cout <<"animal sound : ";
	animal->makeSound();
	std::cout <<"dog sound : ";
	dog->makeSound();
	std::cout <<"cat sound : ";
	cat->makeSound();
	std::cout <<std::endl;

	delete animal;
	delete dog;
	delete cat;

	std::cout <<"----------------------------------------------" << std::endl;

	WrongAnimal *wronganimal = new WrongAnimal();
	WrongAnimal *wrongcat = new WrongCat();
	std::cout <<std::endl;

	std::cout <<"wronganimal type : " <<wronganimal->getType() << std::endl;
	std::cout <<"wrongcat type : "<<wrongcat->getType() << std::endl;
	std::cout <<std::endl;

	std::cout <<"wronganimal sound : ";
	wronganimal->makeSound();
	std::cout <<"wrongcat sound : ";
	wrongcat->makeSound();
	std::cout <<std::endl;

	delete wronganimal;
	delete wrongcat;

	return 0;
}