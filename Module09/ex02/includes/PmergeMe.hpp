#include <iostream>
#include <list>
#include <vector>
#include <cstdlib> //for atoi
#include <climits>
#include <ctime>

template <typename T>
class PmergeMe
{
	private:
		T _container;
	public:
		PmergeMe(T array);
		// PmergeMe(std::vector<int> array);
		// PmergeMe(std::list<int> array);
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe & operator=(PmergeMe const & rhs);

		std::vector<int> divideAndMerge(std::vector<int> array);
		std::list<int> divideAndMerge(std::list<int> array);

		T merge(T left, T right);
		void check_unsigned_int(T array);

		T getSortedArray();
};

template <typename T>
PmergeMe<T>::~PmergeMe() //GRAMMAR: rajouter <std::vector> entre PmergeMe et :: devant toutes les fonctions!!
{
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe<T> const & other)
{
	*this = other;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe<T> const & rhs)
{
	_container = rhs._container;
	return *this;
}

template <typename T>
void PmergeMe<T>::check_unsigned_int(T array)
{
	for (typename T::iterator it = array.begin(); it != array.end(); ++it)
	{
		if (*it < 0)
			throw std::invalid_argument("Error: nb < 0. Expected unsigned int only.");
		if (*it > INT_MAX)
			throw std::invalid_argument("Error: nb > INT_MAX. Expected unsigned int only.");
	}
}

template <typename T>
PmergeMe<T>::PmergeMe(T array)
{
	//_container = ""; //TEST tester valgrind
	check_unsigned_int(array);

	/* std::cout << "Before:";
	for (typename T::iterator it = array.begin(); it != array.end(); ++it) //GRAMMAR: rajouter devant std::vector::iterator
		std::cout << " " << *it;
	std::cout << std::endl; */

	T sortedArray = divideAndMerge(array);

	/* std::cout << "After:";
	for (typename T::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl; */
}

template <typename T>
std::vector<int> PmergeMe<T>::divideAndMerge(std::vector<int> array)
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

template <typename T>
std::list<int> PmergeMe<T>::divideAndMerge(std::list<int> array)
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

template <typename T>
T PmergeMe<T>::merge(T left, T right)
{
	// std::cout <<"IN MERGE FUNCTION" << std::endl;

	// std::vector<int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			_container.push_back(left.front());
			left.erase(left.begin());
		} else {
			_container.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Append the remaining elements of left (if any)
	while (!left.empty()) {
		_container.push_back(left.front());
		left.erase(left.begin());
	}

	// Append the remaining elements of right (if any)
	while (!right.empty()) {
		_container.push_back(right.front());
		right.erase(right.begin());
	}

	return _container;
}

template <typename T>
T PmergeMe<T>::getSortedArray()
{
	return _container;
}