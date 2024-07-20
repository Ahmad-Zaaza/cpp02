#ifndef FIXED_H

# define FIXED_H

# include <iostream>

class Fixed
{
  private:
	int _value;
	static const int FRACTIONAL_BITS;

  public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	Fixed(const Fixed &original);
	Fixed &operator=(const Fixed &original);

	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
