#include "Weapon.hpp"
#include <string>

#ifndef HUMANB_HPP
#define HUMANB_HPP

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
	private:
		Weapon		*weapon;
		std::string	name;
};

#endif