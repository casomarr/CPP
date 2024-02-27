#include "Weapon.hpp"
#include <string>

#ifndef HUMANA_HPP
#define HUMANA_HPP

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
	private:
		Weapon		&weapon;
		std::string	name;
};

#endif