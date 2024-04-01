#include "includes/Span.hpp"

int main()
{
	try
	{
		std::cout <<"EMPTY LIST" <<std::endl;
		Span sp;
		std::cout << sp.longestSpan() <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() <<std::endl <<std::endl;
	}

	try
	{
		std::cout <<"NORMAL LIST" <<std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() <<std::endl;
		std::cout << sp.longestSpan() <<std::endl <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() <<std::endl <<std::endl;
	}

	try
	{
		std::cout <<"TOO MANY NB" <<std::endl;

		Span sp = Span(2);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() <<std::endl;
		std::cout << sp.longestSpan() <<std::endl <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() <<std::endl <<std::endl;
	}

	try
	{
		std::cout <<"COPY" <<std::endl;

		Span sp = Span(5);
		sp.addNumber(42);
		sp.addNumber(30);
		sp.addNumber(17);

		std::cout << sp.shortestSpan() <<std::endl;
		std::cout << sp.longestSpan() <<std::endl;

		Span sp2 = sp;
		std::cout << sp2.shortestSpan() <<std::endl;
		std::cout << sp2.longestSpan() <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() <<std::endl <<std::endl;
	}

	return 0;
}