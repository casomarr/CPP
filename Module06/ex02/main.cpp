#include "includes/Base.hpp"

int main()
{
	Base base;
	Base *random_class;

	random_class = base.generate();
	base.identify(random_class);
	base.identify(*random_class);

	delete random_class;

	return 0;
}