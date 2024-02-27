#include "Fixed.hpp"

/********************************************************************/
/*                    CONSTRUCTORS & DESTRUCTORS                    */
/********************************************************************/

Fixed::Fixed()
{
	// std::cout <<"Default constructor called" <<std::endl;
	_value = 0;
}

/* Copy constructor : sets to _value the value of
_value in copy */
Fixed::Fixed(const Fixed &copy)
{
	// std::cout <<"Copy constructor called" <<std::endl;
	_value = copy.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout <<"Destructor called" <<std::endl;
}

/* Converts the constant integer sent in parameters to
the corresponding fixed-point value */
Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
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
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(nb * (1 << _nb_of_bits));
}


/********************************************************************/
/*                    PRIVATE ATTRIBUTE MODIFIERS                   */
/********************************************************************/

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


/********************************************************************/
/*                             OPERATORS                            */
/********************************************************************/

/************Assignation************/

/* Copy assignment operator overload : assigns to _value of a Fixed
variable the value of _value from the Fixed variable sent in parameters */
Fixed	&Fixed::operator=(const Fixed &nb)
{
	// std::cout <<"Copy assignment operator called" <<std::endl;
	_value = nb.getRawBits();
	return (*this);
}

/************Comparison************/

Fixed	Fixed::operator>(const Fixed &nb) const
{
	return (_value > nb.getRawBits());
}

Fixed	Fixed::operator<(const Fixed &nb) const
{
	return (_value < nb.getRawBits());
}

Fixed	Fixed::operator>=(const Fixed &nb) const
{
	return (_value >= nb.getRawBits());
}

Fixed	Fixed::operator<=(const Fixed &nb) const
{
	return (_value <= nb.getRawBits());
}

Fixed	Fixed::operator==(const Fixed &nb) const
{
	return (_value == nb.getRawBits());
}

Fixed	Fixed::operator!=(const Fixed &nb) const
{
	return (_value != nb.getRawBits());
}

/************Arithmetic************/

Fixed	Fixed::operator+(const Fixed &nb) const
{
	return (Fixed(this->toFloat() + nb.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &nb) const
{
	return (Fixed(this->toFloat() - nb.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &nb) const
{
	return (Fixed(this->toFloat() * nb.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &nb) const
{
	return (Fixed(this->toFloat() / nb.toFloat()));
}

/************Pre/post (in)/(de)crementation************/

/* _nb_of_bits is what influences by how much the display
will increase or dicrease. With _nb_of_bits = 8, with i = 0
and doing i++ we get an increase of 1/2^8 (= 1/256) = 0.0039.
Concretely i in bits = 0000 0000
by making i++ we are bitshifting by _nb_of_bits to the right
i.getRawBits() so we are adding a 1 on the far right :
i = 0000 0001.
Since our operator << displays i.toFloat() we get 0.0039 */

Fixed	&Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this); // creates a copy of the current object
	operator++(); // increments the current object
	return (tmp); //returns the copy (before incrementation)
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}


/********************************************************************/
/*                       COMPARISON FUNCTIONS                       */
/********************************************************************/

Fixed	&Fixed::min(Fixed &fixedPointA, Fixed &fixedPointB)
{
	if (fixedPointA.getRawBits() < fixedPointB.getRawBits())
		return (fixedPointA);
	return (fixedPointB);
}

Fixed	&Fixed::max(Fixed &fixedPointA, Fixed &fixedPointB)
{
	if (fixedPointA.getRawBits() > fixedPointB.getRawBits())
		return (fixedPointA);
	return (fixedPointB);
}

const Fixed	&Fixed::min(const Fixed &fixedPointA, const Fixed &fixedPointB)
{
	if (fixedPointA.getRawBits() < fixedPointB.getRawBits())
		return (fixedPointA);
	
	return (fixedPointB);
}

const Fixed	&Fixed::max(const Fixed &fixedPointA, const Fixed &fixedPointB)
{
	if (fixedPointA.getRawBits() > fixedPointB.getRawBits())
		return (fixedPointA);
	return (fixedPointB);
}


/********************************************************************/
/*                       NON-MEMBER FUNCTIONS                       */
/********************************************************************/

/* Inserts a floating-point representation of the fixed-point
number into the output stream object passed as parameter.
This function declares an operator that overloads the << operator. */
std::ostream	&operator<<(std::ostream &output, const Fixed &nb)
{
	output << nb.toFloat();
	return (output);
}