#include "../includes/Base.hpp"

Base::~Base()
{
}

Base *Base::generate(void)
{
	std::srand(std::time(0)); //use current time as seed for random generator : avoid having the same random number every time we run the program
	int random_number = std::rand() % 3 + 1; //% max number and +1 to avoid starting at 0

	switch (random_number)
	{
		case 1:
			return new A;
		case 2:
			return new B;
		default:
			return new C;
	}
}

/*Dynamic cast : used to check if an object 
being casted is actually of the target type and
returns a nullptr/NULL if the cast is not valid:
dynamic_cast<new_type*>(expression)*/
void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout <<"The object is of type A" <<std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout <<"The object is of type B" <<std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout <<"The object is of type C" <<std::endl;
	else
		std::cout <<"The object's type was not recognized" <<std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast< A& >(p);
		std::cout <<"The object is of type A" <<std::endl;
		(void)a;
	}
	catch(const std::exception& e) {} //On peut preciser quelles exceptions on veut catch (ex: std::badcast). std::exception = toutes les exceptions.

	try
	{
		B& b = dynamic_cast< B& >(p);
		std::cout <<"The object is of type B" <<std::endl;
		(void)b;
	}
	catch(const std::exception& e) {}

	try
	{
		C& c = dynamic_cast< C& >(p);
		std::cout <<"The object is of type C" <<std::endl;
		(void)c;
	}
	catch(const std::exception& e) {}
}