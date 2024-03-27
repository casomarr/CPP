#include "iter.hpp"

int main()
{
	int nb_array[3] = {1, 2, 3};
	std::string string_array[3] = {"yes", "no", "maybe"};

	iter<int>(&nb_array[0], sizeof(nb_array)/sizeof(nb_array[0]), print_elements<int>);
	iter<std::string>(&string_array[0], sizeof(string_array)/sizeof(string_array[0]), print_elements<std::string>);

	/*Explication de pourquoi "sizeof(nb_array)/sizeof(nb_array[0])" :
	. sizeof(nb_array) gives the total size of the array in bytes.
	. sizeof(nb_array[0]) gives the size of one element of the array in bytes.*/
}