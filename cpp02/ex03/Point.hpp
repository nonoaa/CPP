#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	Point& operator=(const Point &src);
	const Fixed &getX(void) const;
	const Fixed &getY(void) const;
	~Point();
};

#endif