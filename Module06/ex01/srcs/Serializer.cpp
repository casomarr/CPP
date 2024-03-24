#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &copy)
{
	(void)copy;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return *this;
}

Serializer::~Serializer()
{
}

/*Reinterpret cast is used to convert a pointer or object to 
another typically used for casting between unrelated types:
reinterpret_cast<new_type>(expression)*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}