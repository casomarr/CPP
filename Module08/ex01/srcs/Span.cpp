#include "../includes/Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n) : _max_nb(n)
{
	//(void)n; //FIX : if I initialize it here it puts n zeros in my vector so push_back adds numbers after the zeros.
	_list = std::vector<int>(0);
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	_list = other._list;
	//_max_nb = _max_nb;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
	//std::cout <<"list size = " <<_list.size() <<std::endl; //TEST

	if (_list.size() >= _max_nb)
		throw std::runtime_error("Too many elements in list");
	else
		_list.push_back(nb);
}

unsigned int Span::shortestSpan()
{
	
	//TEST --------------------------
/*	std::vector<int>::iterator test = _list.begin();
	while(test != _list.end())
	{
		std::cout <<*test <<", ";
		test++;
	}
	std::cout <<std::endl <<std::endl;*/
	//------------------------

	if (_list.size() < 2)
		throw std::runtime_error("Too few numbers in list to calculate span");
	
	int span = INT_MAX;
	int current_span;
	std::vector<int>::iterator it = _list.begin();
	std::vector<int>::iterator next;
	while(it != _list.end())
	{
		next = it + 1;
		current_span = *next - *it;
		//std::cout <<"current_span = " <<current_span <<std::endl; //TEST
		if (current_span < 0)
			current_span *= -1;
		if (current_span < span)
			span = current_span;
		it++;
	}
	if (span >= 0)
		return span;
	else
		return (span * -1); //ex: -10 - (-5 ) doit return 5 et non -5
}

unsigned int Span::longestSpan()
{
	if (_list.size() < 2)
		throw std::runtime_error("Too few numbers in list to calculate span");

	//min and max_element functions return an iterator!! not an int
	std::vector<int>::iterator min = std::min_element(_list.begin(), _list.end());
	std::vector<int>::iterator max = std::max_element(_list.begin(), _list.end());

	//TEST --------------------------
/*	std::vector<int>::iterator test = _list.begin();
	while(test != _list.end())
	{
		std::cout <<*test <<", ";
		test++;
	}
	std::cout <<"min = " <<*min <<std::endl;
	std::cout <<"max = " <<*max <<std::endl;*/
	//------------------------

	return (*max - *min); //"*" because it's what the iterator is pointing to
}