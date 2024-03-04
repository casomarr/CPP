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

//-------> REPRENDRE LE MAIN D'ALBAN ET LE REFAIRE A MA SAUCE POUR BIEN COMPRENDRE L'EXERCICE

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* villain = new Character("villain");

	AMateria* materia;
	materia = src->createMateria("ice");

	std::cout <<std::endl <<"Villain :" <<std::endl;
	std::cout <<"equips ice * 4" <<std::endl <<std::endl;
	villain->equip(materia);
	villain->equip(materia);
	villain->equip(materia);
	villain->equip(materia);

	Character* victim = new Character("victim");

	Character* hero = new Character("hero");

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

	std::cout <<std::endl <<"Victim tries to throw ice to the villain :" <<std::endl;
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


//--------------------- OTHER PERSONAL TESTS ---------------------

/* // DELETE OF UNEQUIPED MATERIA
	IMateriaSource* src = new MateriaSource();
	Character *villain = new Character("villain");
	std::cout <<"Villain equips ice" <<std::endl <<std::endl;
	villain->equip(src->createMateria("ice"));
	std::cout <<"Villain unequips ice" <<std::endl <<std::endl;
	AMateria *tmp = villain->getMateria(0); //to free after unequip, otherwise materia lost
	villain->unequip(0);
	delete tmp;

// DEEP COPIES
	std::cout <<"Hero = villain" <<std::endl <<std::endl;
	Character *hero = new Character(*villain);
	std::cout <<"Villain deleted" <<std::endl <<std::endl;
	delete villain;
	std::cout <<"Hero's name :" <<hero->getName() <<std::endl <<std::endl;
	delete hero;
	delete src;
	
	return 0; */








//ALBAN ---> verifier que j'ai bien tous ses tests dans mes tests perso!!!
	/* std::cout << "Constructors test for Materia" << std::endl;

    AMateria *ice1 = new Ice();
    AMateria *cure1 = new Cure();
    AMateria *cure2 = cure1->clone();

    std::cout << std::endl << "ice1's address : " << ice1 << " and type : " << ice1->getType() << std::endl;
    std::cout << "cure1's address : " << cure1 << " and type : " << cure1->getType() << std::endl;
    std::cout << "cure2's address : " << cure2 << " and type : " << cure2->getType() << std::endl;
  

    std::cout << std::endl << "Constructors test for MateriaSource :" << std::endl;

    IMateriaSource  *src = new MateriaSource();

    std::cout << std::endl << "------Test of MateriaSource learnMateria method :" << std::endl;

    src->learnMateria(ice1);
    src->learnMateria(cure1);
    src->learnMateria(NULL);
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    std::cout << std::endl << "Test of MateriaSource createMateria method :" << std::endl;

    AMateria *ice2 = src->createMateria("ice");
    std::cout << std::endl << "ice2's address : " << ice2 << " and type : " << ice2->getType() << std::endl << std::endl;

    AMateria *cure3 = src->createMateria("cure");
    std::cout << std::endl << "cure3's address : " << cure3 << " and type : " << cure3->getType() << std::endl << std::endl;

    AMateria *banane = src->createMateria("banane");
    std::cout << std::endl << "banane's address : " << banane << std::endl << std::endl;

    std::cout << std::endl << "Delete of materiae's which won't be used later, the delete of cure2 will show us that the materiae copy is deep since it was cloned from cure1. If we can access cure1 just after, everything's good :" << std::endl;
    delete cure3;
    delete ice2;
    delete cure2;
    std::cout << "cure1's address : " << cure1 << " and type : " << cure1->getType() << std::endl;

    std::cout << std::endl << "Test of the Characters Constructors : " << std::endl;
    Character   *newman = new Character();
    Character   *abott = new Character("Jack Abott");

    std::cout << std::endl << "-------------------Test of Characters methods" << std::endl;
    newman->equip(src->createMateria("ice"));
    newman->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("ice"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    abott->equip(src->createMateria("cure"));
    std::cout << std::endl;
    newman->use(0, *abott);
    newman->use(1000, *abott);
    newman->use(2, *abott);
    abott->use(1, *newman);

    std::cout << std::endl << "We will use the unequip method, since the unequip mustn't delete the materia, we will stock it's address in a tmp and delete it afterhand" << std::endl;
    AMateria    *tmp;
    tmp = newman->getMateria(1);
    newman->unequip(1);
    delete tmp;
    newman->unequip(1);
    newman->unequip(1000);
    newman->use(1, *abott);
   
    std::cout << std::endl << "We will now see if the copy of the character and his materiae is deep. If we can still use abott after deleting abott2, it's all good !" << std::endl;
    Character *abott2 = new Character((*(Character*)abott));

    abott2->use(0, *abott);
    delete abott2;
    abott->use(0, *newman);

    std::cout << std::endl << "We will now call the destructors for remaining characters and MateriaSource, it must call destructors for their materiae.";
    
    std::cout << std::endl << "Newman :" << std::endl;
    delete newman;
    std::cout << std::endl << "Abott :" << std::endl;
    delete abott;
    std::cout << std::endl << "Src :" << std::endl;
    delete src;
    return(0); */
}