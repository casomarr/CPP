#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class	Weapon
{
	public:
		Weapon(std::string weapon);
		~Weapon();
		const std::string	&getType(); //returns a const ref on type
		void	setType(std::string value); //attributes value to type

	private:
		std::string	type;
};

#endif