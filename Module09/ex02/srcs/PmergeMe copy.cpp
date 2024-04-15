#include "../includes/PmergeMe.hpp"

PmergeMe::~PmergeMe() //GRAMMAR: rajouter <std::vector> entre PmergeMe et :: devant toutes les fonctions!!
{
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const & rhs)
{
	(void)rhs;
	return *this;
}

void PmergeMe::check_unsigned_int(std::vector<int> array)
{
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
	{
		if (*it < 0)
			throw std::invalid_argument("Error: nb < 0. Expected unsigned int only.");
		if (*it > INT_MAX)
			throw std::invalid_argument("Error: nb > INT_MAX. Expected unsigned int only.");
	}
}

PmergeMe::PmergeMe(std::vector<int> array)
{
	check_unsigned_int(array);

	std::cout << "Before:";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it) //GRAMMAR: rajouter devant std::vector::iterator
		std::cout << " " << *it;
	std::cout << std::endl;

	std::vector<int> sortedArray = divideAndMerge(array);

	std::cout << "After:";
	for (std::vector<int>::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::vector<int> PmergeMe::divideAndMerge(std::vector<int> array)
{
	// std::cout <<"IN DIVIDE FUNCTION" << std::endl;

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
	// std::cout <<"IN MERGE FUNCTION" << std::endl;

	// std::vector<int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			container.push_back(left.front());
			left.erase(left.begin());
		} else {
			container.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Append the remaining elements of left (if any)
	while (!left.empty()) {
		container.push_back(left.front());
		left.erase(left.begin());
	}

	// Append the remaining elements of right (if any)
	while (!right.empty()) {
		container.push_back(right.front());
		right.erase(right.begin());
	}

	return container;
}



void PmergeMe::check_unsigned_int(std::list<int> array)
{
	for (std::list<int>::iterator it = array.begin(); it != array.end(); ++it)
	{
		if (*it < 0)
			throw std::invalid_argument("Error: nb < 0. Expected unsigned int only.");
		if (*it > INT_MAX)
			throw std::invalid_argument("Error: nb > INT_MAX. Expected unsigned int only.");
	}
}

PmergeMe::PmergeMe(std::list<int> array)
{
	check_unsigned_int(array);

	std::cout << "Before:";
	for (std::list<int>::iterator it = array.begin(); it != array.end(); ++it) //GRAMMAR: rajouter devant std::list::iterator
		std::cout << " " << *it;
	std::cout << std::endl;

	std::list<int> sortedArray = divideAndMerge(array);

	std::cout << "After:";
	for (std::list<int>::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::list<int> PmergeMe::divideAndMerge(std::list<int> array)
{
	// std::cout <<"IN DIVIDE FUNCTION" << std::endl;

	if (array.size() <= 1)
		return array;

	//IMPORTANT: DIFFERENCE AVEC VECTOR :
	// std::list<int>::iterator middle = array.begin() + (array.size() / 2);
	std::list<int>::iterator middle = array.begin();
	std::advance(middle, array.size() / 2);

	std::list<int> leftArray(array.begin(), middle); //plus propre et court que de faire une while qui copie/colle numero par numero et i++
	std::list<int> rightArray(middle, array.end());

	// Recursively splitting the arrays
	leftArray = divideAndMerge(leftArray);
	rightArray = divideAndMerge(rightArray);

	// Merging the arrays and returning
	return merge(leftArray, rightArray);
}

std::list<int> PmergeMe::merge(std::list<int> left, std::list<int> right)
{
	// std::cout <<"IN MERGE FUNCTION" << std::endl;

	// std::list<int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			container.push_back(left.front());
			left.erase(left.begin());
		} else {
			container.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Append the remaining elements of left (if any)
	while (!left.empty()) {
		container.push_back(left.front());
		left.erase(left.begin());
	}

	// Append the remaining elements of right (if any)
	while (!right.empty()) {
		container.push_back(right.front());
		right.erase(right.begin());
	}

	return container;
}
