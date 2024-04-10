#include "../includes/BitcoinExchange.hpp"

std::string		BitcoinExchange::getDate(std::string line)
{
	std::string date;
	int i = 0;

	while (line[i] != ' ' && line[i])
	{
		date = date + line[i]; //IMPORTANT: date[i] = line[i] ne marchr pas en c++!!!!
		i++;
	}
	if (line[i] == '\0' || line[i+1] != '|')
		throw std::runtime_error("Error: wrong line format in .csv file");
	return date;
}

std::string		BitcoinExchange::getValue(std::string line)
{
	std::string str_value = "";
	int i = 0;

	while (line[i] != '|' && line[i])
		i++;
	if (line[i] == '\0' || line[i+1] != ' ')
		throw std::runtime_error("Error: wrong line format in .csv file");
	i++; //to skip space
	while(line[i] != '\0')
	{
		// value = value * 10 + (line[i] -'0');
		//str_value[i] = line[i];
		str_value = str_value + line[i];
		i++;
	}
	return str_value;
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	int year = 0;
	int month = 0;
	int day = 0;

	for (int i = 0; i < 4 ; i++)
		year = year * 10 + (date[i] - '0');
	for (int i = 5; i < 7 ; i++)
		month = month * 10 + (date[i] - '0');
	for (int i = 8; i < 10 ; i++)
		day = day * 10 + (date[i] - '0');

	// std::cout <<"Date = " <<date <<std::endl;
	// std::cout <<"year = " <<year <<" | month = " <<month <<" | day = " <<day <<std::endl;

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2) //leap year
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		if (day > 29)
			return false;
		} else {
		if (day > 28)
			return false;
		}
	}

	return true;
};

void	BitcoinExchange::checkDateFormat(std::string date)
{
	for (int i = 0; i < 4; i++)
		if (std::isdigit(static_cast<unsigned char>(date[i])) == 0) //not a nb
			throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (date[4] != '-')
		throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	for (int i = 5; i < 7; i++)
		if (std::isdigit(static_cast<unsigned char>(date[i])) == 0) //not a nb
			throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (date[7] != '-')
		throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	for (int i = 8; i < 10; i++)
		if (std::isdigit(static_cast<unsigned char>(date[i])) == 0) //not a nb
			throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (date[10] != '\0')
		throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (isValidDate(date) == false)
		throw std::runtime_error("Unexisting date");
}

int	BitcoinExchange::checkValueFormat(std::string str_value)
{
	long long int value = -1;

	long unsigned int i = 0;
	unsigned int pointCount = 0;

	while(str_value[i] != '\0')
	{
		if (std::isdigit(str_value[i]) == 0 && str_value[i] != '.') //if not a digit
		{
			if (str_value[i] == '.') //if it's a point
			{
				pointCount++;
				if (pointCount > 1)
					throw std::runtime_error("Error : only int and float numbers accepted");
			}
		}
		i++;
	}
	
	if (value == -1)
		value = atoll(str_value.c_str());

	if (value < 0)
		throw std::runtime_error("Error : negative number");
	if (value > INT_MAX)
		throw std::runtime_error("Error : number > INT_MAX");

	return value;
}

int	BitcoinExchange::checkValueFormat(long long int value)
{
	// std::string str_value;

	// str_value = itoa(value);
	// itoa(value, str_value.c_str(), 10);

	//equivalent of itoa in c++
	std::stringstream ss;
	ss << value;
	std::string str_value = ss.str();

	unsigned int pointCount = 0;

	long unsigned int i = 0;
	while(str_value[i] != '\0')
	{
		if (std::isdigit(static_cast<unsigned char>(str_value[i])) == 0/*  && str_value[i] != '.' */) //if not a digit
		{
			if (str_value[i] == '.') //if it's a point
			{
				pointCount++;
				if (pointCount > 1)
					throw std::runtime_error("Error : only int and float numbers accepted");
			}
		}
		i++;
	}

	if (value < 0)
		throw std::runtime_error("Error : negative number");
	if (value > 1000)
		throw std::runtime_error("Error : number > 1000");

	return value;
}

void	BitcoinExchange::fill_info(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string str_value;
	int value;
	static int first_line = 0;

	while (std::getline(file, line))
	{
		if (first_line == 0) //to skip title line
			first_line++;
		else
		{
			date = "";
			str_value = "";
			value = -1;

			try //FIX ce try and catch ne change rien du coup 1000 + 1 dans fichier n'est pas catch
			{
				date = getDate(line);
				checkDateFormat(date);

				str_value = getValue(line);
				value = checkValueFormat(str_value);
			}
			catch(const std::exception& e)
			{
				//std::cerr << e.what() << '\n'; //sinon avec throw en bas ca ecrirait deux fois l exception
				//std::cout <<"EXCEPTION CAUGHT HERE" <<std::endl; //TEST
				throw; //re-throw exception
				//return ;
			}
			
			_info[date] = value;
		}
	}
	if (_info.empty() == true)
	{
		std::cout <<"Error: file is empty" <<std::endl;
		_file_data_ok = false;
	}

}

bool	BitcoinExchange::wrong_type(std::string const &filename)
{
	unsigned int i = filename.length();

	if (filename[i] == 'v' && filename[i-1] == 's' && filename[i-2] == 'c' && filename[i-3] == '.')
		return true;
	return false;
}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
	_file_data_ok = true;
	try
	{
		if (wrong_type(filename) == true)
			throw std::runtime_error("wrong file type : expected .csv");

		std::ifstream	file;
		file.open(filename.c_str(), std::ios::in);
		if (!file)
			throw std::runtime_error("wrong filename : failed to open file");
		fill_info(file);
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		_file_data_ok = false;
		return ;
		//throw; //re-throw exception
	}
}

BitcoinExchange::~BitcoinExchange()
{
	_file_data_ok = true;
	//IMPORTANT: _file_data_ok = true; et _info les mettre dans constructeur par default, de copy et = !!!
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_info = rhs._info;
	return *this;
}

void BitcoinExchange::exchangeRate(std::string date, long long int nb)
{
	if (_file_data_ok == false)
	{
		std::cout <<"Error in file : can't run exchangeRate" <<std::endl;
		return;
	}
	try
	{
		checkDateFormat(date);
		checkValueFormat(nb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	
	std::map<std::string, int>::iterator it; //IMPORTANT: it->first (key) / it->second (value)
	it = _info.find(date);
	if (it == _info.end())
	{
		it = _info.lower_bound(date);

		if (it == _info.begin() && it->first != date) 
		{
			std::cout << "No preceding date found" << std::endl;
			return;
		}
		--it; // Move to the closest preceding date
	}
	std::cout <<"Date = " <<it->first <<" | Exchange Rate = " <<it->second <<std::endl;
	std::cout <<"Result = " <<it->second <<" * " <<nb <<" = ";
	std::cout <<(it->second * nb) <<std::endl <<std::endl;
}