#include "includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Expected: " << "./PmergeMe " << "int int int int [...]" << std::endl;
		return 1;
	}

	std::vector<int> vector(0);
	for (int i = 1; i < argc; i++)
		vector.push_back(atoi(argv[i]));

	std::list<int> list(vector.begin(), vector.end()); //transforms vector into list to keep the same numbers

	try
	{
		clock_t start = clock();
		// PmergeMe <std::vector<int> >pmergeVector(vector);
		PmergeMe pmergeVector(vector);
		clock_t end = clock();
		std::cout << "Time to process a range of " <<argc -1 <<" elements with std::vector : " \
		<<(double)(end - start) <<" us" <<std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		clock_t start = clock();
		// PmergeMe <std::list<int> >pmergeList(list);
		PmergeMe pmergeVector(list);
		clock_t end = clock();
		std::cout << "Time to process a range of " <<argc -1 <<" elements with std::list : " \
		<<(double)(end - start) <<" us" <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/*POUR QUE CE SOIT EXACTEMENT COMME DANS LE SUJET DE CORRECTION IL FAUDRAIT
	METTRE SEULEMENT DEUX FONCTIONS EN PUBLIC : UN GETTEUR QUI PRINT LE VECTEUR
	OU LA LIST SORTED DEPUIS LE MAIN (POUR PAS QUE ÇA S'AFFICHE EN DOUBLE) AINSI
	QUE LE CONSTRUCTEUR ET LE DECONSTRUCTEUR PAR DÉFAULT (ET LES AUTRES FONCTIONS)
	DE LA FORME CANIONIQUE SI ON VEUT). tOUTES ES AUTRES FONCTIONS N'ONT AUCUNE
	RAISON D'ÊTRE NE PUBLIC.*/
	
	return 0;
}