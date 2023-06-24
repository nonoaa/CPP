#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(10.0f, 10.0f);

	std::cout << bsp(a, b, c, Point(5.0f, 2.0f)) << std::endl;

	return 0;
}