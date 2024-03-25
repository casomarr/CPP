#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdint.h> //for type uintptr_t

struct Data
{
	int nb;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &rhs);

	public:
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};