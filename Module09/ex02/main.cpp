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

	// std::vector<int> array_to_pint = vector.getSortedArray();
	PmergeMe<std::vector<int> > pmerge(vector); 
	std::vector<int> array_to_pint = pmerge.getSortedArray(); //HERE (works)

	std::cout << "Before:";
	for (std::vector<int>::iterator it = array_to_pint.begin(); it != array_to_pint.end(); ++it) //GRAMMAR: rajouter devant std::vector::iterator
		std::cout << " " << *it;

	std::cout << std::endl;
	try
	{
		clock_t start = clock();
		PmergeMe<std::vector<int> > pmergeVector(vector);
		clock_t end = clock();


		std::cout << "After:";
		for (std::vector<int>::iterator it = array_to_pint.begin(); it != array_to_pint.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl;


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
		PmergeMe<std::list<int> > pmergeVector(list);
		clock_t end = clock();
		std::cout << "Time to process a range of " <<argc -1 <<" elements with std::list : " \
		<<(double)(end - start) <<" us" <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}