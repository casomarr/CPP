#pragma once

#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <cstdlib> //for atoi
#include <sstream> //for stringstream (equivalent of itoa)
#include <fstream> //for getline
#include <cfloat> //for FLT_MAX

#define CSV 1
#define TXT 2

class BitcoinExchange
{
	private:
		std::map <std::string, float> _csv;
		std::map <std::string, std::string> _txt;
		bool _file_data_ok;

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

	public:
		BitcoinExchange(std::string const &filename);
		~BitcoinExchange();

		void			exchangeRate(std::string const &filename);
		bool			wrong_type(std::string const &filename, int fileType);
		void			fill_info(std::ifstream &file);
		std::string		getDate(std::string line);
		std::string		getValue(std::string line);
		void			checkDateFormat(std::string date);
		float			checkValueFormat(std::string str_value);
		float			checkValueFormat(float value);
		bool			isValidDate(std::string date);

};