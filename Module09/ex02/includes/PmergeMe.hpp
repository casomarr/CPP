#include <iostream>
#include <list>
#include <vector>
#include <cstdlib> //for atoi

class PmergeMe
{
	private:
		// std::vector<int> _leftArray;
		// std::vector<int> _rightArray;
		// std::list<int> _SortedArray;
		// std::vector<int> *sortedarray;
		std::vector<int> sortedarray;


	public: 
		// PmergeMe(std::vector<int> *array);
		PmergeMe(std::vector<int> array);
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe & operator=(PmergeMe const & rhs);

		// void	divideArray(std::vector<int> *array);
		// void	mergeArray(std::vector<int> *leftArray, std::vector<int> *rightArray/* , std::vector<int> array*/);
		// void	mergeArray(std::vector<int> leftArray, std::vector<int> rightArray/* , std::vector<int> array*/);
		// void	divideArray(std::vector<int> array);
		// void	mergeArray(const std::vector<int>& leftArray, const std::vector<int>& rightArray);

		std::vector<int> divideAndMerge(std::vector<int> array);
		std::vector<int> merge(std::vector<int> left, std::vector<int> right);
};