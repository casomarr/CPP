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
		Array() {};
		~Array()
		{
			// for (int i = 0; i < size(); i++) //boucle necessaire?
			// 	delete _array[i];
			//delete _array;
			//delete[] _array;
		};

		Array(Array const &copy)
		{
			// for (int i = 0; i < copy._array.size(); i++)
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		};

		Array &operator=(Array const &rhs)
		{
			delete[] _array; //avec []
			// _array = new T[rhs._array.size()];
			_array = new T[_size];
			// for (int i = 0; i < rhs._array.size(); i++)
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		};

		Array(unsigned int n) : _size(n)
		{
			_array = new T[n];
			// std::fill_n(_array, n, T()); //to fill with default value (0 for digits for example)
		};
		unsigned int size() const
		{
			//return sizeof(_array)/sizeof(_array[0]); //sizeof() instead of size() because it's an array
			return _size;
		};
/* 		T &operator[](size_t index) //operator [] pour les objets de type T
		{
			try
			{
				if (_array[index] != NULL)
					return _array[index];
			}
			catch(const std::exception& e) {};
		} */
		/* T &operator[](size_t index) //operator [] pour les objets de type T
		{
			try
			{
				if (index >= size())
				{
					std::cout<<"Index out of array range" <<std::endl;
					throw std::exception();
				}
				//return _array[index];
			}
			catch(const std::exception& e) {};
			return _array[index];
		}; */
		T &operator[](size_t index) //operator [] pour les objets de type T
		{
			if (index >= size())
			{
				std::cout<<"Index out of array range" <<std::endl;
				throw std::exception();
			}
			return _array[index];
		};
};