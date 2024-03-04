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

	const WrongAnimal *wrongcat1 = new WrongCat();
	const WrongCat *wrongcat2 = new WrongCat();

	std::cout <<std::endl;

	std::cout <<"wrongcat1 type : " <<wrongcat1->getType() << std::endl;
	std::cout <<"wrongcat2 type : "<<wrongcat2->getType() << std::endl;
	std::cout <<std::endl;

	std::cout <<"wrongcat1 sound : ";
	wrongcat1->makeSound();
	std::cout <<"wrongcat2 sound : ";
	wrongcat2->makeSound();
	std::cout <<std::endl;

	delete wrongcat1;
	delete wrongcat2;

	return 0;
}