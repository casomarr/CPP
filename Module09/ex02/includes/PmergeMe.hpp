#include <iostream>
#include <list>
#include <vector>
#include <cstdlib> //for atoi
#include <climits>
#include <ctime>

// #include "../srcs/PmergeMe.cpp"

class PmergeMe
{
	public: 
		PmergeMe(std::vector<int> array);
		PmergeMe(std::list<int> array);
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe & operator=(PmergeMe const & rhs);

		std::vector<int> divideAndMerge(std::vector<int> array);
		std::vector<int> merge(std::vector<int> left, std::vector<int> right);
		void check_unsigned_int(std::vector<int> array);

		std::list<int> divideAndMerge(std::list<int> array);
		std::list<int> merge(std::list<int> left, std::list<int> right);
		void check_unsigned_int(std::list<int> array);
};

// #include "../srcs/PmergeMe.cpp"