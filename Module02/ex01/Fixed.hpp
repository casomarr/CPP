#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(Fixed const &nb);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		//added in this exercise :
		Fixed(const int nb);
		Fixed(const float nb);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int _value;
		static const int _nb_of_bits = 8;;
};

std::ostream	&operator<<(std::ostream &output, Fixed const &nb);

#endif