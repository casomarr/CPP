#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap = ClapTrap("Clap");
	clap.setAttackDammages(10);
	ScavTrap scav = ScavTrap("Scav");
	FragTrap frag = FragTrap("Frag");

	std::cout<<std::endl<<std::endl;

	frag.highFivesGuys();
	std::cout<<std::endl<<std::endl;

	/* They all attack each other. Scav Trap is the 
	last one standing since ClapTrap has very few 
	_hitPoints and once ClapTrap is dead ScavTrap 
	doesn't get any more damages */
	for (int i = 0; i < 5; i++)
	{
		std::cout <<"Clap's life points = " <<(int)clap.getHitPoints() <<std::endl;
		std::cout <<"Scav's life points = " <<(int)scav.getHitPoints() <<std::endl;
		std::cout <<"Frag's life points = " <<(int)frag.getHitPoints() <<std::endl;
		std::cout<<std::endl;
	
		clap.attack("Scav");
		if (clap.getHitPoints() > 0)
			scav.takeDamage(clap.getAttackDammages());
		scav.attack("Frag");
		if (scav.getHitPoints() > 0)
			frag.takeDamage(scav.getAttackDammages());
		frag.attack("Clap");
		if (frag.getHitPoints() > 0)
			clap.takeDamage(frag.getAttackDammages());
		std::cout<<std::endl;
	}
	std::cout <<"Clap's life points = " <<(int)clap.getHitPoints() <<std::endl;
	std::cout <<"Scav's life points = " <<(int)scav.getHitPoints() <<std::endl;
	std::cout <<"Frag's life points = " <<(int)frag.getHitPoints() <<std::endl;
	std::cout<<std::endl<<std::endl;

	return 0;
}