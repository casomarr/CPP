// #ifndef PMERGEME_HPP
// #include "../includes/PmergeMe.hpp"
// #endif

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
	(void)rhs;
	return *this;
}

void check_unsigned_int(T array)
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
	check_unsigned_int(array);

	std::cout << "Before:";
	for (typename T::iterator it = array.begin(); it != array.end(); ++it) //GRAMMAR: rajouter typename devant T::iterator
		std::cout << " " << *it;
	std::cout << std::endl;

	T sortedArray = divideAndMerge(array);

	std::cout << "After:";
	for (typename T::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename T>
T PmergeMe<T>::divideAndMerge(T array)
{
	// std::cout <<"IN DIVIDE FUNCTION" << std::endl;

	if (array.size() <= 1)
		return array;

	typename T::iterator middle = array.begin() + (array.size() / 2);
	T leftArray(array.begin(), middle); //plus propre et court que de faire une while qui copie/colle numero par numero et i++
	T rightArray(middle, array.end());

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

	T result;
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
