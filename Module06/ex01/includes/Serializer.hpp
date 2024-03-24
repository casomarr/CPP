#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <stdint.h> //for type uintptr_t

/*CHECK: "Do not forget to turn in the files of your Data structure."
--> veut dire que je dois mettre la struct Data dans un autre fichier??*/
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