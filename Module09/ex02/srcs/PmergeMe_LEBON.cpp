#include "../includes/PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
	*this = other;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	(void)rhs;
	return *this;
}

//-----------------------------------------------------------------

PmergeMe::PmergeMe(std::vector<int> array)
{
	std::cout << "Before:";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::vector<int> sortedarray = divideAndMerge(array);
	//IMPORTANT : pas oublier d'utiliser 2 containers différents!! Avec un template?

	std::cout << "After:";
	for (std::vector<int>::iterator it = sortedarray.begin(); it != sortedarray.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

std::vector<int> PmergeMe::divideAndMerge(std::vector<int> array)
{
	std::cout <<"IN DIVIDE FUNCTION" << std::endl;

	if (array.size() <= 1)
		return array;

	std::vector<int>::iterator middle = array.begin() + (array.size() / 2);
	std::vector<int> leftArray(array.begin(), middle); //plus propre et court que de faire une while qui copie/colle numero par numero et i++
	std::vector<int> rightArray(middle, array.end());

	// Recursively splitting the arrays
	leftArray = divideAndMerge(leftArray);
	rightArray = divideAndMerge(rightArray);

	// Merging the arrays and returning
	return merge(leftArray, rightArray);
}

std::vector<int> PmergeMe::merge(std::vector<int> left, std::vector<int> right)
{
	std::cout <<"IN MERGE FUNCTION" << std::endl;

	std::vector<int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		} else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Append the remaining elements of left (if any)
	while (!left.empty()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}

	// Append the remaining elements of right (if any)
	while (!right.empty()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}

	return result;
}
