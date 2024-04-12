#include "includes/BitcoinExchange.hpp"

int main (int argc, char **argv) 
{
 	if (argc != 2)
	{
		std::cerr << "Expected: ./btc <file>" << std::endl;
		return 1;
	}

	std::cout <<"WRONG FILENAMES" <<std::endl;
	//wrong csv file
	try
	{
		BitcoinExchange bitcoin("UnexistantFile.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		BitcoinExchange bitcoin("WrongFileType.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		BitcoinExchange bitcoin("input_wrong.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<std::endl;

	try
	{
		BitcoinExchange bitcoin("input.csv");
		bitcoin.exchangeRate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}