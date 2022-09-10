#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value_ = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    value_ = value << fractionalBits_;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    value_ = static_cast<int>(roundf(value * (1 << fractionalBits_)));
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value_ = src.value_;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value_);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value_ = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(value_) / (1 << fractionalBits_));
}

int Fixed::toInt(void) const
{
    return (value_ >> fractionalBits_);
}

std::ostream& operator<<(std::ostream &out, const Fixed &ref)
{
    out << ref.toFloat();
    return (out);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}