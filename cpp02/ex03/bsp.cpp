#include "Point.hpp"

float crossProduct(Point &p1, Point &p2)
{
	// std::cout << (p1.getX().toFloat() * p2.getY().toFloat()) - (p2.getX().toFloat() * p1.getY().toFloat()) << std::endl;
	return ((p1.getX().toFloat() * p2.getY().toFloat()) - (p2.getX().toFloat() * p1.getY().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab = Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point bc = Point(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());
	Point ca = Point(a.getX().toFloat() - c.getX().toFloat(), a.getY().toFloat() - c.getY().toFloat());

	Point ap = Point(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());
	Point bp = Point(point.getX().toFloat() - b.getX().toFloat(), point.getY().toFloat() - b.getY().toFloat());
	Point cp = Point(point.getX().toFloat() - c.getX().toFloat(), point.getY().toFloat() - c.getY().toFloat());

	float crossA = crossProduct(ap, ab);
	float crossB = crossProduct(bp, bc);
	float crossC = crossProduct(cp, ca);

	if ((crossA > 0 && crossB > 0 && crossC > 0)
		|| (crossA < 0 && crossB < 0 && crossC < 0))
		return true;
	return false;
}