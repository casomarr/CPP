#include "includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Expected: " << "./PmergeMe " << "int int int int [...]" << std::endl;
		return 1;
	}
	
	//PASSER ARRAY EN TYPE LIST POUR UTILISER DEUX CONTAINERS DIFFERENTS
	// std::vector<int> *array = new std::vector<int>(0);
	// for (int i = 1; i < argc; i++)
	// 	array->push_back(atoi(argv[i]));

	std::vector<int> array(0);
	for (int i = 1; i < argc; i++)
		array.push_back(atoi(argv[i]));

	/* int[] array;
	for (int i = 1; i < argc; i++)
		array[i - 1] = atoi(argv[i]) */

	PmergeMe pmerge(array);
	
	return 0;
}