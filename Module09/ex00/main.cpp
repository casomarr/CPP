#include "includes/BitcoinExchange.hpp"

int main (int argc, char **argv) 
{
 	if (argc != 2)
	{
		std::cerr << "Expected: ./btc <file>" << std::endl;
		return 1;
	}

	std::cout << "WRONG FILE" << std::endl << std::endl;

	//wrong file
	{
		BitcoinExchange bitcoin("UnexistantFile.csv");
	}
	{
		BitcoinExchange bitcoin("WrongFileType.txt");
	}

	std::cout <<std::endl << "EXISTING FILE AND CORRECT PARAMETERS" << std::endl << std::endl;

	//right file
	BitcoinExchange bitcoin(argv[1]);

	//same date with different values
	bitcoin.exchangeRate("2021-10-06", 1);
	bitcoin.exchangeRate("2021-10-06", 3);

	std::cout /* <<std::endl */ << "DATE NOT IN .CSV : closest date taken into account" << std::endl << std::endl;
	
	//date not in .csv : takes the closest date
	bitcoin.exchangeRate("2027-10-06", 1);
	bitcoin.exchangeRate("1600-10-06", 1);

	std::cout <<std::endl << "WRONG VALUES PASSED AS PARAMETERS" << std::endl << std::endl;

	//wrong way to write the date
	bitcoin.exchangeRate("2021/10/06", 1);
	bitcoin.exchangeRate("06-10-2021", 1);

	//unexisting date
	bitcoin.exchangeRate("2021-42-42", 1);

	//int max : "error : number too large"
	bitcoin.exchangeRate("2019-07-04", 2147483648);

	//value is not a positive value
	bitcoin.exchangeRate("2021-10-06", -3);

	return 0;
}
