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

	IMateriaSource* src = new MateriaSource();
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
	delete src;

//--------------------- PERSONAL TESTS ---------------------

/* 	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* villain = new Character("villain");

	std::cout <<std::endl <<"Villain :" <<std::endl;
	std::cout <<"equips ice * 4" <<std::endl <<std::endl;
	villain->equip(src->createMateria("ice"));
	villain->equip(src->createMateria("ice"));
	villain->equip(src->createMateria("ice"));
	villain->equip(src->createMateria("ice"));

	Character* victim = new Character("victim");

	Character* hero = new Character("hero");

	std::cout <<std::endl <<"Hero :" <<std::endl;
	std::cout <<"equips ice * 1" <<std::endl;
	hero->equip(src->createMateria("ice"));
	std::cout <<"equips cure * 1" <<std::endl <<std::endl ;
	hero->equip(src->createMateria("cure"));

	std::cout <<std::endl <<"Villain :" <<std::endl;
	for (int i = 0; i < 4; i++)
		villain->use(i, *victim);

	std::cout <<std::endl <<"Hero :" <<std::endl;
	hero->use(0, *villain);
	hero->use(1, *victim);

	std::cout <<std::endl <<"Victim tries to throw ice to the villain :" <<std::endl;
	victim->use(0, *villain);
	std::cout <<std::endl;

	
	delete villain;

	delete src;
	delete victim;
	delete hero;

//--------------------- OTHER PERSONAL TESTS ---------------------

	{
// DELETE OF UNEQUIPED MATERIA
	std::cout <<std::endl <<"------------Delete of unequiped materia------------------" <<std::endl <<std::endl;
	IMateriaSource* src = new MateriaSource();
	Character *villain = new Character("villain");
	std::cout <<std::endl <<"Villain equips ice" <<std::endl <<std::endl;
	villain->equip(src->createMateria("ice"));
	std::cout <<"Villain unequips ice" <<std::endl <<std::endl;
	AMateria *tmp = villain->getMateria(0); //to free after unequip, otherwise materia lost
	villain->unequip(0);
	delete tmp;

// DEEP COPIES
	std::cout <<"------------Deep Copy------------------" <<std::endl <<std::endl;
	std::cout <<"Hero = villain" <<std::endl <<std::endl;
	Character *hero = new Character(*villain);
	std::cout <<"Villain deleted" <<std::endl <<std::endl;
	delete villain;
	std::cout <<"Hero's name : " <<hero->getName() <<std::endl <<std::endl;
	delete hero;
	delete src;
	} */

	return 0;
}