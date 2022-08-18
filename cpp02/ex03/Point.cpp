#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)){}

Point::Point(const Point &src): x(src.x), y(src.y) {}

Point &Point::operator=(const Point &src)
{
	const_cast<Fixed &>(this->x) = src.x;
	const_cast<Fixed &>(this->y) = src.y;

	return (*this);
}

const Fixed &Point::getX(void) const
{
	return (x);
}

const Fixed &Point::getY(void) const
{
	return (y);
}

Point::~Point(){}