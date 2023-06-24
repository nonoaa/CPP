#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value_;
    static const int fractionalBits_ = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream &out, const Fixed &ref);

#endif