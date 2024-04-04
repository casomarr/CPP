#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments. Ex: ./rpn \"1 2 3 + -\"" << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		RPN rpn(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
