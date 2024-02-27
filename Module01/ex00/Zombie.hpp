#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
	public:
		Zombie(std::string name_arg);
		~Zombie();
		void	announce(void);
	private:
		std::string	name;
};

#endif