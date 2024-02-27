#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap = ClapTrap("Clap");
	clap.setAttackDammages(5);
	ScavTrap scav = ScavTrap("Scav");
	std::cout<<std::endl;

	//initial life points
	std::cout <<"Clap's life points = " <<clap.getHitPoints() <<std::endl;
	std::cout <<"Scav's life points = " <<scav.getHitPoints() <<std::endl;

	std::cout<<std::endl;
	//scav and clap attack each other
	clap.attack("Scav");
	if (clap.getHitPoints() > 0)
	{
		scav.takeDamage(clap.getAttackDammages());
		std::cout <<"Scav's life points = " <<scav.getHitPoints() <<std::endl;
	}
	scav.attack("Clap");
	if (scav.getHitPoints() > 0)
	{
		clap.takeDamage(scav.getAttackDammages());
		std::cout <<"Clap's life points = " <<(int)clap.getHitPoints() <<std::endl;
	}
	std::cout<<std::endl;

	//clap is dead
	clap.attack("Scav");
	std::cout<<std::endl;

	//clap reborns
	clap.beRepaired(100);
	std::cout <<"Clap's life points = " <<(int)clap.getHitPoints() <<std::endl;
	std::cout<<std::endl;

	//scav gets in Gate Keeper mode
	scav.guardGate();
	std::cout<<std::endl;

	return 0;
}