#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(Fixed const &value);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _value;
		static const int _nb_of_bits = 8;;
};

std::ostream &operator<<(std::ostream &o, Fixed const &value);

#endif