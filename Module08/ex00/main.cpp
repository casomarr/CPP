#include "includes/easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	int nb = 2;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, nb);
		std::cout <<"Value being searched : " <<nb <<". Value found in vector : " <<&it <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	try
	{
		std::cout <<"Test with container of type vector" <<std::endl;
		std::cout <<"Value being searched : " <<nb <<". Value found in vector : " <<*easyfind(vec, nb) <<std::endl;

		std::cout <<"Test with container of type list" <<std::endl;
		std::cout <<"Value being searched : " <<nb <<". Value found in list : " <<*easyfind(lst, nb) <<std::endl <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	
	nb = 6;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, nb);
		std::cout <<"Value being searched : " <<nb <<". Value found in vector is " <<*it <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}

	return 0;
}

