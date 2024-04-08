#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> *array) : sortedarray(array)
{
	std::cout <<"Before:";
	for (std::vector<int>::iterator it = array->begin(); it != array->end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	divideArray(array);

	std::cout <<"After: ";
	for (std::vector<int>::iterator it = sortedarray->begin(); it != sortedarray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
}

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

void	PmergeMe::divideArray(std::vector<int> *array)
{

	// std::cout <<"Array size: " <<array->size() <<std::endl; //TEST

	if (array->size() <= 1)
		return;

	// std::cout <<"Array: "; //TEST
	// for (std::vector<int>::iterator TEST = array->begin(); TEST != array->end(); TEST++)
	// 	std::cout <<" " <<*TEST;
	// std::cout <<std::endl;

	std::vector<int>::iterator it = array->begin();
	long unsigned int i = 0;

	// std::vector<int> leftArray(0);
	// std::vector<int> rightArray(0);
	std::vector<int>* leftArray = new std::vector<int>(0); //avec new et -> et * partout ne change rien donc autant le supprimer sinon les delete vont etre un enfer
	std::vector<int>* rightArray = new std::vector<int>(0);

	while (i < array->size())
	{
		if (i < array->size() / 2)
			leftArray->push_back(*it);
		else
			rightArray->push_back(*it);
		it++;
		i++;
	}

//-------------------------------
 std::cout <<"DIVIDE: " <<std::endl;
	{
	std::cout <<"LEFT: ";
	for (std::vector<int>::iterator it = leftArray->begin(); it != leftArray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	{
	std::cout <<"RIGHT: ";
	for (std::vector<int>::iterator it = rightArray->begin(); it != rightArray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	{
	std::cout <<"sortedarray: ";
	for (std::vector<int>::iterator it = sortedarray->begin(); it != sortedarray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	std::cout <<std::endl;
//-------------------------------

	divideArray(leftArray);
	divideArray(rightArray);
	mergeArray(leftArray, rightArray/* , array */);
}

void	PmergeMe::mergeArray(std::vector<int> *leftArray, std::vector<int> *rightArray/* , std::vector<int> array */)
{
	sortedarray->clear();//TEST

	std::vector<int>::iterator l = leftArray->begin();
	std::vector<int>::iterator r = rightArray->begin();
	// static std::vector<int>::iterator s = sortedarray->begin(); //TEST

	// std::cout <<"BEGINING s: " <<*s <<std::endl; //TEST

	while (l != leftArray->end() && r != rightArray->end())
	{
		if (*l < *r)
		{
			sortedarray->push_back(*l);
			// *s = *l; //TEST
			l++;
		}
		else
		{
			sortedarray->push_back(*r);
			// *s = *r; //TEST
			r++;
		}
		// s++; //TEST
	}
	
	while( l != leftArray->end())
	{
		sortedarray->push_back(*l); //nb dans leftArray sont deja en ordre croissant
		// *s = *l; //TEST
		l++;
		// s++; //TEST
	}
	while( r != rightArray->end())
	{
		sortedarray->push_back(*r);
		// *s = *r; //TEST
		r++;
		// s++; //TEST
	}

	// std::cout <<"END s: " <<*s <<std::endl; //TEST

//-------------------------------
 std::cout <<"MERGE: " <<std::endl;
	{
	std::cout <<"LEFT: ";
	for (std::vector<int>::iterator it = leftArray->begin(); it != leftArray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	{
	std::cout <<"RIGHT: ";
	for (std::vector<int>::iterator it = rightArray->begin(); it != rightArray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	{
	std::cout <<"sortedarray: ";
	for (std::vector<int>::iterator it = sortedarray->begin(); it != sortedarray->end(); it++)
		std::cout <<" " <<*it;
	std::cout <<std::endl;
	}
	std::cout <<std::endl;
//-------------------------------
}