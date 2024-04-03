#include "../includes/Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n) : _max_nb(n)
{
	/*if I initialize it here such as :
	_list = std::vector<int>(n);
	it puts n zeros in my vector so push_back adds numbers after the zeros.*/
	_list = std::vector<int>(0);
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	_list = other._list;
	_max_nb = other._max_nb;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
	if (_list.size() >= _max_nb)
		throw std::runtime_error("Too many elements in list");
	else
		_list.push_back(nb);
}

void Span::addNumber(int start, int end, unsigned int length) 
{
	std::vector<int> nb_list;
	unsigned int i = 0;

	srand(static_cast<unsigned int>(std::time(0)));

	while(i < length) 
	{
		if (_list.size() >= _max_nb)
			throw std::runtime_error("Too many elements in list");
		else
		{
			_list.push_back(rand() % (end - start + 1) + start);
		}
		i++;
	}
}

unsigned int Span::shortestSpan()
{
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

	return (*max - *min); //"*" because it's what the iterator is pointing to
}