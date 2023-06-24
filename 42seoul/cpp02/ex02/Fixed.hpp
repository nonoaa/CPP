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

    bool operator>(const Fixed& ref);
    bool operator<(const Fixed& ref);
    bool operator>=(const Fixed& ref);
    bool operator<=(const Fixed& ref);
    bool operator==(const Fixed& ref);
    bool operator!=(const Fixed& ref);

    Fixed operator+(const Fixed& ref);
    Fixed operator-(const Fixed& ref);
    Fixed operator*(const Fixed& ref);
    Fixed operator/(const Fixed& ref);

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);

    ~Fixed();
};

std::ostream& operator<<(std::ostream &out, const Fixed &ref);

#endif