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
		std::cout <<"NORMAL LIST calling addNumber repeatedly" <<std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() <<std::endl;
		std::cout << sp.longestSpan() <<std::endl <<std::endl;

		std::cout <<"NORMAL LIST calling addNumber only once with 10 000 values" <<std::endl;

		Span sp2 = Span(10000);
		sp2.addNumber(42, 94242, 10000);

		std::cout << sp2.shortestSpan() <<std::endl;
		std::cout << sp2.longestSpan() <<std::endl <<std::endl;

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

		std::cout <<"Spans for sp" <<std::endl;
		std::cout << sp.shortestSpan() <<std::endl;
		std::cout << sp.longestSpan() <<std::endl;

		Span sp2 = sp;
		std::cout <<"sp2 = sp" <<std::endl;
		std::cout <<"Spans for sp2" <<std::endl;
		std::cout << sp2.shortestSpan() <<std::endl;
		std::cout << sp2.longestSpan() <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() <<std::endl <<std::endl;
	}

	return 0;
}