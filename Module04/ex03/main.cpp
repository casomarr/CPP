#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* villain = new Character("villain");

	AMateria* ice;
	ice = src->createMateria("ice");
	villain->equip(ice);
	villain->equip(ice);
	villain->equip(ice);

	ICharacter* victim = new Character("victim");
	victim->equip(ice);

	ICharacter* hero = new Character("hero");

	hero->equip(ice);
	AMateria* cure;
	cure = src->createMateria("cure");
	hero->equip(cure);

	std::cout <<std::endl <<"Villain's actions :" <<std::endl;
	for (int i = 0; i < 4; i++)
		villain->use(i, *victim);

	std::cout <<std::endl <<"Hero's actions :" <<std::endl;
	hero->use(0, *villain);
	hero->use(1, *victim);
	std::cout <<std::endl;


//LA PARTIE CI-DESSOUS CRÉE DES LEAKS! MAIS AU PIRE PRINT INVENTORY N'EST PAS OBLIGATOIRE MAIS ÇA PERMET DE VÉRIFIER UNEQUIP
/* 	Character* character = dynamic_cast<Character*>(victim); //to be able to use printInventory() since it is in the Character class but not the ICharacter class
	std::cout <<"Victims' inventory : " <<std::endl;
	character->printInventory();
	std::cout <<std::endl;
	victim->unequip(0);
	std::cout <<"Victims' inventory after unequiping : " <<std::endl;
	character->printInventory();
	std::cout <<std::endl; */

	delete villain;
	delete hero;
	delete victim;
	delete src;
	delete ice; //faudrait pas les delete dans des fonctions?
	delete cure; //faudrait pas les delete dans des fonctions?
	delete character;

	return 0;
}