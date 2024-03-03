#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{

//--------------------- MAIN TESTS ---------------------

/* 	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src; */

//--------------------- PERSONAL TESTS ---------------------

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* villain = new Character("villain");

	AMateria* materia;
	materia = src->createMateria("ice");

	std::cout <<std::endl <<"Villain :" <<std::endl;
	std::cout <<"equips ice * 4" <<std::endl <<std::endl;
	villain->equip(materia/* ->clone() */); //en commantant ça, ça leak. Pourquoi ici et pas dans les equip suivants? vérifier deep copies etc
	villain->equip(materia/* ->clone() */);
	villain->equip(materia/* ->clone() */);
	villain->equip(materia/* ->clone() */);

	ICharacter* victim = new Character("victim");
	std::cout <<std::endl <<"Victim :" <<std::endl;
	std::cout <<"equips ice * 1" <<std::endl <<std::endl;
	victim->equip(materia);

	ICharacter* hero = new Character("hero");

	std::cout <<std::endl <<"Hero :" <<std::endl;
	std::cout <<"equips ice * 1" <<std::endl <<std::endl;
	hero->equip(materia);
	materia = src->createMateria("cure");
	std::cout <<std::endl <<"Hero :";
	std::cout <<std::endl <<"equips cure * 1" <<std::endl;
	hero->equip(materia);

	std::cout <<std::endl <<"Villain :" <<std::endl;
	for (int i = 0; i < 4; i++)
		villain->use(i, *victim);

	std::cout <<std::endl <<"Hero :" <<std::endl;
	hero->use(0, *villain);
	hero->use(1, *victim);

	std::cout <<std::endl <<"Victim :" <<std::endl;
	std::cout <<"unequips ice * 1 but still tries to throw it at the villain" <<std::endl;
	victim->unequip(0);
	victim->use(0, *villain);

	std::cout <<std::endl <<"Hero2 = Hero :" <<std::endl;
	ICharacter *hero2 = hero;
	hero2->use(0, *villain);
	hero2->use(1, *victim);
	std::cout <<std::endl;

	delete src;
	delete villain;
	delete victim;
	delete hero;
	
	return 0;
}