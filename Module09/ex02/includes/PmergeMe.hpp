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
PmergeMe<T>::~PmergeMe() //GRAMMAR: rajouter <T> entre PmergeMe et :: devant toutes les fonctions!!
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
PmergeMe<T>::PmergeMe(T array) : _container(0)
{
	check_unsigned_int(array);
	T sortedArray = divideAndMerge(array);
}

template <typename T>
std::vector<int> PmergeMe<T>::divideAndMerge(std::vector<int> array)
{
	if (array.size() <= 1)
		return array;

	std::vector<int>::iterator middle = array.begin() + (array.size() / 2);
	std::vector<int> leftArray(array.begin(), middle);
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
	if (array.size() <= 1)
		return array;

	/*The two following lines are the only difference 
	between the divideAndMerge function for vector or list*/
	std::list<int>::iterator middle = array.begin();
	std::advance(middle, array.size() / 2);

	std::list<int> leftArray(array.begin(), middle);
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

	_container.clear();

	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			_container.push_back(left.front());
			left.erase(left.begin());
		} else {
			_container.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Appends the remaining elements of leftArray (if any)
	while (!left.empty()) {
		_container.push_back(left.front());
		left.erase(left.begin());
	}

	// Appends the remaining elements of rightArray (if any)
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