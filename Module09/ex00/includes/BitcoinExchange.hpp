#pragma once

#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <stdlib.h> //necessaire?
#include <cstdlib> //for atoi
#include <sstream> //pour équivalent de itoa
#include <istream> //necessaire?
#include <fstream> //getline

class BitcoinExchange
{
	private:
		std::map <std::string, int> _info;
	public:
		BitcoinExchange(std::string const &filename);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void			exchangeRate(std::string date, int nb);
		bool			wrong_type(std::string const &filename);
		void			fill_info(std::ifstream &file);
		std::string		getDate(std::string line);
		std::string		getValue(std::string line);
		void			checkDateFormat(std::string date);
		int				checkValueFormat(std::string str_value);
		int				checkValueFormat(int value);
};