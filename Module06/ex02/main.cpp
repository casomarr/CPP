#include "includes/Base.hpp"

int main()
{
	Base base;
	Base *random_class;

	random_class = base.generate();
	base.identify(random_class);
	base.identify(*random_class);

	return 0;
}

//FIX: qd j'esssaye de compiler ça dit qu'il faut -std=c++11 pour que ça marche