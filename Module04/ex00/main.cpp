#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout <<"--------------Main tests--------------" << std::endl  <<std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout <<std::endl <<"--------------------Animal tests----------------" << std::endl <<std::endl;

	// Dog *dog = new Dog();
	// Cat *cat = new Cat();

	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
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

	std::cout <<std::endl <<"--------------------Wrong Animal tests----------------" << std::endl <<std::endl;

	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();
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