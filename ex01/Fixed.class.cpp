#include "./Fixed.hpp"
#include <cmath>
#include <ostream>

int const Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _value(val << Fixed::FRACTIONAL_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float val) : _value(roundf(val
		* (1 << Fixed::FRACTIONAL_BITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
	return ;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
	{
		this->_value = original.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return ;
}

float Fixed::toFloat() const
{
	return (this->getRawBits()
		/ static_cast<float>(1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> Fixed::FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &i)
{
	ostream << i.toFloat();
	return (ostream);
}
