#include "includes/BitcoinExchange.hpp"

int main (int argc, char **argv) 
{
 	if (argc != 2)
	{
		std::cerr << "Expected: ./btc <file>" << std::endl;
		return 1;
	}

	try
	{
		std::cout <<"WRONG FILENAME" <<std::endl;
		BitcoinExchange bitcoin("UnexistantFile.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"WRONG TYPE FILE" <<std::endl;
		BitcoinExchange bitcoin("test_files/WrongFileType.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"WRONG INPUT FILE" <<std::endl;
		BitcoinExchange bitcoin("test_files/input_wrong.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"EMPTY CSV FILE" <<std::endl;
		BitcoinExchange bitcoin("test_files/input_empty.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"EMPTY TXT FILE" <<std::endl;
		BitcoinExchange bitcoin("test_files/input.csv");
		bitcoin.exchangeRate("test_files/empty_file.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<std::endl <<"-----------------------------" <<std::endl;
	try
	{
		std::cout <<"ERRORS IN TXT FILE" <<std::endl;
		BitcoinExchange bitcoin("test_files/input.csv");
		bitcoin.exchangeRate("test_files/errors_file.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<std::endl <<"-----------------------------" <<std::endl;

	std::cout <<"WORKING FILE" <<std::endl;
	try
	{
		BitcoinExchange bitcoin("test_files/input.csv");
		bitcoin.exchangeRate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}