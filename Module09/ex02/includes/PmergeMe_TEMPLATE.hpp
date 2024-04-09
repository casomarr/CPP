#include <iostream>
#include <list>
#include <vector>
#include <cstdlib> //for atoi

// #include "../srcs/PmergeMe.cpp"

template <typename T>
class PmergeMe
{
	public: 
		PmergeMe(T array);
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe & operator=(PmergeMe const & rhs);

		T divideAndMerge(T array);
		T merge(T left, T right);
		void check_unsigned_int(T array);
};

#include "../srcs/PmergeMe.cpp"