#include "Fixed.hpp"

int main( void )
{
	//subject tests
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	//comparison tests
	{
		Fixed a = Fixed(5.05f);
		Fixed b = Fixed(2);
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
	}

	//comparison functions tests
	{
		Fixed a = Fixed(5.05f);
		Fixed b = Fixed(2);
		// std::cout << a.min(a, b) << std::endl;
		// std::cout << b.min(a, b) << std::endl;
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		const Fixed &a = Fixed(5.05f);
		const Fixed &b = Fixed(2);
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	//arithmetic tests
	{
		Fixed a = Fixed(5.05f);
		Fixed b = Fixed(2);
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}

	//pre/post (in)/(de)crementation
	{
		Fixed a = Fixed(5);
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
	}

	return 0;
}