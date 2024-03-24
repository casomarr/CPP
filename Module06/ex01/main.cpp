#include "includes/Serializer.hpp"

int main()
{
	Data data;
	data.nb = 42;

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	//FIX
	//STD::TO_STRING = ITOA
	std::cout <<"Original pointer's value =" <<std::to_string(&data) << std::endl;
	std::cout <<"Serialized pointer's value =" <<std::to_string(serialized) << std::endl;

	return 0;
}