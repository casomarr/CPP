#include "../includes/BitcoinExchange.hpp"

std::string		BitcoinExchange::getDate(std::string line)
{
	std::string date;
	int i = 0;

	while (line[i] != ',' && line[i])
	{
		date = date + line[i]; //IMPORTANT: date[i] = line[i] ne marche pas en c++!!!!
		i++;
	}
	if (line[i] == '\0' || line[i] != ',')
		throw std::runtime_error("Error: wrong line format. Expecting : YYYY-MM-DD,value");
	return date;
}

std::string		BitcoinExchange::getValue(std::string line)
{
	std::string str_value = "";
	int i = 0;

	while (line[i] != ',' && line[i])
		i++;
	if (line[i] == '\0' || line[i] != ',')
		throw std::runtime_error("Error: wrong line format. Expecting : YYYY-MM-DD,value");
	i++; //to skip coma
	while(line[i] != '\0')
	{
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
		if (std::isdigit(static_cast<unsigned char>(date[i])) == 0)
			throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (date[7] != '-')
		throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	for (int i = 8; i < 10; i++)
		if (std::isdigit(static_cast<unsigned char>(date[i])) == 0)
			throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (date[10] != '\0')
		throw std::runtime_error("Wrong date Format. Expecting : YYYY-MM-DD");
	if (isValidDate(date) == false)
		throw std::runtime_error("Unexisting date");
}

float	BitcoinExchange::checkValueFormat(std::string str_value)
{
	if (str_value == "ERROR")
		throw std::runtime_error("Error: line format");
	float value = -1;

	long unsigned int i = 0;
	unsigned int pointCount = 0;

	while(str_value[i] != '\0')
	{
		if (std::isdigit(str_value[i]) == 0) //if not a digit
		{
			if (str_value[i] == '.')
			{
				pointCount++;
				if (pointCount > 1)
					throw std::runtime_error("Error : only int and float numbers accepted");
			}
		}
		i++;
	}
	
	if (value == -1)
		value = atof(str_value.c_str());

	if (value < 0)
		throw std::runtime_error("Error : negative number");
	long long int value_int = atoll(str_value.c_str());
	if (value_int > INT_MAX)
		throw std::runtime_error("Error : number > INT_MAX");

	return value;
}

float	BitcoinExchange::checkValueFormat(float value)
{
	//equivalent of itoa in c++98
	std::stringstream ss;
	ss << value;
	std::string str_value = ss.str();

	unsigned int pointCount = 0;

	long unsigned int i = 0;
	while(str_value[i] != '\0')
	{
		if (std::isdigit(static_cast<unsigned char>(str_value[i])) == 0) //if not a digit
		{
			if (str_value[i] == '.')
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
	if (value > FLT_MAX)
		throw std::runtime_error("Error : number > FLT_MAX");

	return value;
}

void	BitcoinExchange::fill_info(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string str_value;
	float value;
	int first_line = 0;

	while (std::getline(file, line))
	{
		if (first_line == 0) //to skip title line //CHECK
			first_line++;
		else
		{
			date = getDate(line);
			checkDateFormat(date);

			str_value = getValue(line);
			value = checkValueFormat(str_value);

			_csv[date] = value;
		}
	}
	if (_csv.empty() == true)
	{
		std::cout <<"Error in CSV file: empty file" <<std::endl;
		_file_data_ok = false;
	}
}

bool	BitcoinExchange::wrong_type(std::string const &filename, int fileType)
{

	long unsigned int i = filename.length();
	if (fileType == CSV)
	{
		if (filename[i-1] == 'v' && filename[i-2] == 's' && filename[i-3] == 'c' && filename[i-4] == '.')
			return true;
	}
	else if (fileType == TXT)
	{
		if (filename[i-1] == 't' && filename[i-2] == 'x' && filename[i-3] == 't' && filename[i-4] == '.')
			return true;
	}
	return false;
}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
	_file_data_ok = true;
	try
	{
		if (wrong_type(filename, CSV) == false)
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
		std::cerr <<"Error in CSV file : " <<e.what() << '\n';
		_file_data_ok = false;
		return ;
	}
}

BitcoinExchange::BitcoinExchange()
{
	_file_data_ok = true;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_file_data_ok = rhs._file_data_ok;
	_csv = rhs._csv;
	_txt = rhs._txt;
	return *this;
}

void BitcoinExchange::exchangeRate(std::string const &filename)
{
	if (_file_data_ok == false)
		throw std::runtime_error("Error in CSV file : can't run exchangeRate with .txt file");
	if (wrong_type(filename, TXT) == false)
		throw std::runtime_error("wrong file type : expected .txt");

	std::ifstream	file;
	file.open(filename.c_str(), std::ios::in);
	if (!file)
		throw std::runtime_error("wrong filename : failed to open file");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error in TXT file : empty file");

	std::string line;
	std::string date;
	std::string value;
	int first_line = 0;

	while (std::getline(file, line))
	{
		if (first_line == 0) //to skip title line //CHECK
			first_line++;
		else
		{
			long unsigned int i = 0;
			while (line[i] != ' ' && line[i])
				i++;
			date = line.substr(0, i);
			i+= 3; //to skip " | "
			if (i < line.length())
				value = line.substr(i, line.length());
			else
				value = "ERROR";
			_txt[date] = value;
		}
	}
	file.close();

	std::map<std::string, float>::iterator it_csv; //it->first (key) / it->second (value)
	std::map<std::string, std::string>::iterator it_txt;
	it_txt = _txt.begin();
	float nb;
	bool ok = true;
	while (it_txt != _txt.end())
	{
		ok = true;
		std::cout <<"TXT Date = " <<it_txt->first <<" | " <<"value = " <<it_txt->second <<std::endl;
		try
		{
			checkDateFormat(it_txt->first);
			nb = checkValueFormat(it_txt->second);
			if (nb > 1000)
			{
				std::cout <<"Error in TXT file : value > 1000" <<std::endl;
				ok = false;
			}

			it_csv = _csv.find(it_txt->first);
			if (it_csv == _csv.end())
			{
				it_csv = _csv.lower_bound(it_txt->first);

				if (it_csv == _csv.begin() && it_csv->first != it_txt->first) 
				{
					std::cout << "No preceding date found" << std::endl;
					ok = false;
				}
				if (ok == true)
					--it_csv; // Move to the closest preceding date
			}
			if (ok == true)
			{
				std::cout <<"Corresponding CSV Date = " <<it_csv->first <<" | Exchange Rate = " <<it_csv->second <<std::endl;
				std::cout <<"Result = " <<it_csv->second <<" * " <<nb <<" = ";
				std::cout <<(it_csv->second * nb) <<std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr <<"Error in TXT file : " << e.what() << '\n';
		}
		std::cout <<std::endl;
		it_txt++;
	}
}
