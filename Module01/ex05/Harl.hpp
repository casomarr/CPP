#include <string>
#include <iostream>

#ifndef HARL_HPP
#define HARL_HPP

class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );
	private:
		void (Harl::*levelFunctions[4])();
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif