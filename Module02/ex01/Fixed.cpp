#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout <<"Default constructor called" <<std::endl;
	_value = 0;
}

/* Copy constructor : sets to _value the value of
_value in copy */
Fixed::Fixed(const Fixed &copy)
{
	std::cout <<"Copy constructor called" <<std::endl;
	_value = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" <<std::endl;
}

/* Returns the value of the fixed point number
without converting it */
int	Fixed::getRawBits( void ) const
{
	//std::cout <<"getRawBits member function called" <<std::endl;
	return (_value);
}

/* Initializes the value of the fixed point number
with the one passed as a parameter*/
void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

/* Copy assignment operator overload : assigns to _value of a Fixed
variable the value of _value from the Fixed variable sent in parameters */
Fixed &Fixed::operator=(Fixed const &nb)
{
	std::cout <<"Copy assignment operator called" <<std::endl;
	_value = nb.getRawBits();
	return (*this);
}

/* Converts the constant integer sent in parameters to
the corresponding fixed-point value */
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	_value = nb << _nb_of_bits;
}

/* Converts the constant floating-point number sent
in parameters to the corresponding fixed-point value.
Fixed-point numbers = 16 bits.
1. convert float to int with roundf(floatvalue)
2. convert int to fixed point with bitshifting
We cannot write _value = roundf(nb << _nb_of_bits);
even though it would make more since since we do
nb << _nb_of_bits to convert from int to fixed but
>> and << only work for int (the compiler doesn't know
how to do it for float) so we have to apply the bitshifting
to 1 (which is an int) and then multiply it by nb. */
Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(nb * (1 << _nb_of_bits));
}

/* Converts from fixed-point to float 
1. Convert the fixed-point number as an integer.
2. Divide the number by 2^nb_of_bits (2 to the 
power of nb_of_bits) --> 2^nb_of_bits is the same
as doing << _nb_of_bits but since we are
not allowed to use pow() in this exercice we have
to do it by bitshifting */
float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _nb_of_bits));
}

/* Converts from fixed-point to int */
int	Fixed::toInt( void ) const
{
	return (_value >> _nb_of_bits);
}

/* Inserts a floating-point representation of the fixed-point
number into the output stream object passed in parameter.
This function declares an operator that overloads the << operator. */
std::ostream	&operator<<(std::ostream &output, Fixed const &nb)
{
	output << nb.toFloat();
	return output;
}