#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    value_ = 0;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    value_ = value << fractionalBits_;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    value_ = (int)roundf(value * (1 << fractionalBits_));
}

Fixed::Fixed(const Fixed& src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    value_ = src.value_;
    return (*this);
}

bool Fixed::operator>(const Fixed& ref)
{
    return (value_ > ref.value_);
}

bool Fixed::operator<(const Fixed& ref)
{
    return (value_ < ref.value_);
}

bool Fixed::operator>=(const Fixed& ref)
{
    return (value_ >= ref.value_);
}

bool Fixed::operator<=(const Fixed& ref)
{
    return (value_ <= ref.value_);
}

bool Fixed::operator==(const Fixed& ref)
{
    return (value_ == ref.value_);
}

bool Fixed::operator!=(const Fixed& ref)
{
    return (value_ != ref.value_);
}

Fixed Fixed::operator+(const Fixed& ref)
{
    return (Fixed(toFloat() + ref.toFloat()));
}

Fixed Fixed::operator-(const Fixed& ref)
{
    return (Fixed(toFloat() - ref.toFloat()));
}

Fixed Fixed::operator*(const Fixed& ref)
{
    return (Fixed(toFloat() * ref.toFloat()));
}

Fixed Fixed::operator/(const Fixed& ref)
{
    return (Fixed(toFloat() / ref.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    value_ += 1;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    value_ -= 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    value_ += 1;

    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    value_ -= 1;

    return (temp);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (value_);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    value_ = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)value_ / (1 << fractionalBits_)); 
}

int Fixed::toInt(void) const
{
    return (value_ >> fractionalBits_);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	// std::cout << "(min)";
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	// std::cout << "(const min)";
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	// std::cout << "(max)";
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	// std::cout << "(const max)";
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream &out, const Fixed &ref)
{
    out << ref.toFloat();
    return (out);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}