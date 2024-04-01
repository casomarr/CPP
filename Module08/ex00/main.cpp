//lire Consignes générales du sujet (changent pour CPP8 et 9)
//video intra: https://elearning.intra.42.fr/notions/piscine-c-d08-stl/subnotions/piscine-c-d08-stl-stl/videos/stl-1e60e486-1b8b-4f10-89bd-b2b3871bd3e9

//include <algorithm> --> le but est d utiliser des containers de la STL

#include "easyfind.hpp"

int main()
{
	/*IMPORTANT : on ne peut pas instancier un containeur comme ça : std::vector<int> vec = {1, 2, 3, 4}.
	Il faut utiliser std::push_back().*/

	std::vector<int> vec;
	std::list<int> lst;
	int nb = 2;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, nb);
		std::vector<int>::iterator compare = std::find(vec.begin(), vec.end(), 2);

		//CHECK : ne devraient pas tous avoir la même adresse?
		std::cout <<"First occurence of " <<nb <<" in vector is " <<&it <<std::endl;
		std::cout <<"&vec[1] = " <<&vec[1] <<std::endl;
		std::cout <<"std::find(vec.begining(), vec.end(), 2) = " <<&compare <<std::endl <<std::endl;
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
		std::vector<int>::iterator vec_it = easyfind(vec, nb); //need this line to print with std::cout <<&it ("invalid operands to binary expression" error)
		std::vector<int>::iterator compare = std::find(vec.begin(), vec.end(), 2);

		//CHECK : ne devraient pas tous avoir la même adresse?
		std::cout <<"Test with container of type vector" <<std::endl;
		std::cout <<"First occurence of " <<nb <<" in vector is " <<&vec_it <<std::endl;
		std::cout <<"&vec[1] = " <<&vec[1] <<std::endl;
		std::cout <<"std::find(vec.begining(), vec.end(), 2) = " <<&compare <<std::endl <<std::endl;

		std::list<int>::iterator lst_it = easyfind(lst, nb);
		std::cout <<"Test with container of type list" <<std::endl;
		std::cout <<"First occurence of " <<nb <<" in list is " <<&lst_it <<std::endl <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	
	nb = 6;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, nb);
		std::vector<int>::iterator compare = std::find(vec.begin(), vec.end(), 2);

		//CHECK : ne devraient pas tous avoir la même adresse?
		std::cout <<"First occurence of " <<nb <<" in vector is " <<&it <<std::endl;
		std::cout <<"&vec[1] = " <<&vec[1] <<std::endl;
		std::cout <<"std::find(vec.begining(), vec.end(), 2) = " <<&compare <<std::endl <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}

	return 0;
}

//IMPORTANT : soit j'ai mal comrpis l'exo et je dois mettre std::vector<T> dans le .hpp
