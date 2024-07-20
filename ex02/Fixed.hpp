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

	Fixed &operator=(const Fixed &);
	bool operator==(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator>(const Fixed &) const;
	bool operator!=(const Fixed &) const;

	Fixed operator+(const Fixed &) const;
	Fixed operator-(const Fixed &) const;
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;

	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &, Fixed &);
	static const Fixed &min(Fixed const &, Fixed const &);
	static Fixed &max(Fixed &, Fixed &);
	static const Fixed &max(Fixed const &, const Fixed &);

	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	void setRawBits(int const);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
