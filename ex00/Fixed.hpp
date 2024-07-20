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
	~Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
