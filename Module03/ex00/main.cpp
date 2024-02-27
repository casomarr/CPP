#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1 = ClapTrap("Clap1");
	clap1.setAttackDammages(20);
	ClapTrap clap2 = ClapTrap("Clap2");
	clap2.setAttackDammages(5);

	std::cout<<std::endl;
	//clap2 and clap1 attack each other
	clap2.attack("Clap1");
	if (clap2.getHitPoints() > 0)
	{
		clap1.takeDamage(clap2.getAttackDammages());
		std::cout <<"Clap1's life points = " <<(int)clap1.getHitPoints() <<std::endl;
	}
	clap1.attack("Clap2");
	if (clap1.getHitPoints() > 0)
	{
		clap2.takeDamage(clap1.getAttackDammages());
		std::cout <<"Clap2's life points = " <<(int)clap2.getHitPoints() <<std::endl;
	}
	std::cout<<std::endl;

	//clap2 is dead
	clap2.attack("Clap1");
	std::cout<<std::endl;

	//clap2 reborns
	clap2.beRepaired(100);
	std::cout <<"Clap2's life points = " <<clap2.getHitPoints() <<std::endl;
	clap2.attack("Clap1");
	if (clap2.getHitPoints() > 0)
	{
		clap1.takeDamage(clap2.getAttackDammages());
		std::cout <<"Clap1's life points = " <<(int)clap1.getHitPoints() <<std::endl;
	}
	std::cout<<std::endl;

	//clap2 has no energy points left
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.attack("Clap1");
	std::cout<<std::endl;

	return 0;
}