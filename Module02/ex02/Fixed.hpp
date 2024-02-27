#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	//constructors :
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int nb);
		Fixed(const float nb);

	//functions to modify private attributes :
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	//operators :
		//assignation
		Fixed	&operator=(const Fixed &nb);
		//comparison
		Fixed	operator>(const Fixed &nb) const;
		Fixed	operator<(const Fixed &nb) const;
		Fixed	operator>=(const Fixed &nb) const;
		Fixed	operator<=(const Fixed &nb) const;
		Fixed	operator==(const Fixed &nb) const;
		Fixed	operator!=(const Fixed &nb) const;
		//arithmetic
		Fixed	operator+(const Fixed &nb) const;
		Fixed	operator-(const Fixed &nb) const;
		Fixed	operator*(const Fixed &nb) const;
		Fixed	operator/(const Fixed &nb) const;
		//pre/post (in)/(de)crementation
		Fixed	&operator++(void); //++i
		Fixed	operator++(int); //i++
		Fixed	&operator--(void); //--i
		Fixed	operator--(int); //i--

	//comparison functions :
		static Fixed		&min(Fixed &fixedPointA, Fixed &fixedPointB);
		static Fixed		&max(Fixed &fixedPointA, Fixed &fixedPointB);
		static const Fixed	&min(const Fixed &fixedPointA, const Fixed &fixedPointB);
		static const Fixed	&max(const Fixed &fixedPointA, const Fixed &fixedPointB);

	private:
		int _value;
		static const int _nb_of_bits = 8;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &nb);

#endif