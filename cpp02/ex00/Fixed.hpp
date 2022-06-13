#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int value_;
    static const int fractionalBits_ = 8;

public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};

#endif