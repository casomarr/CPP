#include <iostream>
#include "Array.hpp"

/* #define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
} */

int main()
{
	try
	{
	//CLASS WITH INT AND CHAR
		std::cout <<"CLASS WITH INT AND CHAR" <<std::endl <<std::endl;
		Array<int> array(4);
		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = i;
		std::cout <<"Array size = " <<array.size() <<std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout <<"array[" <<i <<"] : " <<array[i] <<std::endl;
		std::cout <<std::endl;

		Array<std::string> strArray(4);
		for (unsigned int i = 0; i < strArray.size(); i++)
			strArray[i] = 'a' + i;
		std::cout <<"StrstrArray size = " <<strArray.size() <<std::endl;
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout <<"strArray[" <<i <<"] : " <<strArray[i] <<std::endl;
		std::cout <<std::endl;

	//OPERATOR = DEEP COPY
		std::cout <<"OPERATOR = DEEP COPY : " <<std::endl <<std::endl;
		Array<int> array1 = array;
		array[0] = 42;
		std::cout <<"Array1 size = " <<array1.size() <<std::endl;
		for (unsigned int i = 0; i < array1.size(); i++)
			std::cout <<"array1[" <<i <<"] : " <<array1[i] <<std::endl;
		std::cout <<std::endl;

	//COPY CONSTRUCTOR DEEP COPY
		std::cout <<"COPY CONSTRUCTOR DEEP COPY" <<std::endl <<std::endl;
		Array<int> array2(array1);
		array1[0] = 42;
		std::cout <<"Array2 size = " <<array2.size() <<std::endl;
		for (unsigned int i = 0; i < array2.size(); i++)
			std::cout <<"array2[" <<i <<"] : " <<array2[i] <<std::endl;
		std::cout <<std::endl;
	
	//INDEX OUT OF RANGE
		std::cout <<"INDEX OUT OF RANGE" <<std::endl <<std::endl;
		array2[7] = 4;
		std::cout <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<e.what() <<std::endl;
	}

	try
	{
		std::cout <<std::endl;
		std::cout <<"ARRAY INITIALIZED BY DEFAULT" <<std::endl <<std::endl;
		//Creates an array of n elements initialized by default.
		int * a = new int();
		std::cout <<"A : " <<*a <<std::endl;
		delete a;
		std::cout <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<e.what() <<std::endl;
	}

	try
	{
		//Creates an empty array.
		std::cout <<"EMPTY ARRAY" <<std::endl <<std::endl;
		Array<int> array;
		std::cout <<"Array size = " <<array.size() <<std::endl;
		//the following line will not be printed since size = 0
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout <<"array[" <<i <<"] : " <<array[i] <<std::endl;
		//if we force it it will print out of range
		std::cout <<"array[0] : " <<array[0] <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<e.what() <<std::endl;
	}
	
	return 0;
}