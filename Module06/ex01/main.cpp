#include "includes/Serializer.hpp"

int main()
{
	Data data;
	// data.nb = 42;

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout <<"Original pointer's value =" <<&data << std::endl;
	std::cout <<"Serialized pointer's value =" <<deserialized << std::endl;

	// std::cout <<data.nb <<std::endl;

	return 0;
}