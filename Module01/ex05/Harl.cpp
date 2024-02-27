#include "Harl.hpp"

Harl::Harl()
{
	levelFunctions[0] = &Harl::debug;
	levelFunctions[1] = &Harl::info;
	levelFunctions[2] = &Harl::warning;
	levelFunctions[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" <<std::endl;
}
void Harl::info( void )
{
	std::cout<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" <<std::endl;
}
void Harl::warning( void )
{
	std::cout<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<std::endl;
}
void Harl::error( void )
{
	std::cout<< "This is unacceptable ! I want to speak to the manager now." <<std::endl;
}

/* The level array has its strings in the same order as their
corresponding functions. So we just have to compare the string
"level" sent in parameters to the strings in the level array and
if they are equal we call the corresponding function. */
void Harl::complain( std::string level )
{
	std::string	levels_array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4)
	{
		if (levels_array[i].compare(level) == 0)
		{
			(this->*levelFunctions[i])();
			break;
		}
		i++;
	}
	if (i == 4) //no level correspondance
		std::cout <<"Incorret Level : levels accepted are \"DEBUG\", \"INFO\", \"WARNING\" and \"ERROR\"" <<std::endl;
}