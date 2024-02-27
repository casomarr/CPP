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
int Fixed::getRawBits( void ) const
{
	std::cout <<"getRawBits member function called" <<std::endl;
	return (_value);
}

/* Initializes the value of the fixed point number
with the one passed as a parameter*/
void Fixed::setRawBits( int const raw )
{
	std::cout <<"setRawBits member function called" <<std::endl;
	_value = raw;
}

/* Copy assignment operator overload : assigns to _value of a Fixed
variable the value of _value from the Fixed variable sent in parameters */
Fixed &Fixed::operator=(Fixed const &value)
{
	std::cout <<"Copy assignment operator called" <<std::endl;
	_value = value.getRawBits();
	return (*this);
}