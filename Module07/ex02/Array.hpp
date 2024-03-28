#pragma once

#include <iostream>
#include <string>
#include <cstdlib> //for std::srand
#include <ctime> //for std::time

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() 
		{
			_size = 0;
			_array = new T[0];
		};
		~Array()
		{
			delete[] _array; //IMPORTANT delete[] for arrays (int *array = new int[]), delete for single objects (int *unit = new int)
		};

		Array(Array const &copy)
		{
			_size = copy._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		};

		Array &operator=(Array const &rhs)
		{
			delete[] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return *this;
		};

		Array(unsigned int n)
		{
			_size = n;
			_array = new T[n];
			std::fill_n(_array, n, T()); //to fill with default value (0 for digits for example)
			/*IMPORTANT; T() instead of T allows to directly initialize a type. Ex:
			int() = 0, double() = 0.0, std, string() = "" */
		};
		unsigned int size() const
		{
			return _size;
		};
		T &operator[](size_t index) //operator [] pour les objets de type T
		{
			if (index >= size())
				throw std::out_of_range("Index out of array range");
			return _array[index];
		};
};