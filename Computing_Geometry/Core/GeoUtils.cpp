#include "GeoUtils.h"
#include "Base/Vector.cpp"
#include "Base/Core.h"

double jmk::areaTriangle2d(const Point2d& a,const Point2d& b,const Point2d& c) {
	auto AB = b - a;
	auto AC = c - a;
	//叉积就是四边形面积
	auto result = crossProduct2d(AB, AC);

	return result/2;
}


int jmk::orientation2d(const Point2d& a, const Point2d& b, const Point2d& c) {
	auto area = areaTriangle2d(a, b, c);
	if (area > 0 && area < TOLERENCE) 
		area = 0;
	if (area < 0 && area > TOLERENCE)
		area = 0;

	Vector2f ab = b - a;
	Vector2f ac = c - a;

	if (area > 0)
		return LEFT;

	if (area < 0)
		return RIGHT;

	if ((ab[X] * ac[X] < 0) || (ab[Y] * ac[Y] < 0)) {
		return BEHIND;
	}

	if (ab.magnitude() < ac.magnitude()) {
		return BEYOND;
	}

	if (a == c)
		return ORIGIN;
	if (b == c)
		return DESTINATION;


	return BETWEEN;
}

bool jmk::left(const Point2d& a, const Point2d& b, const Point2d& c)
{
	return orientation2d(a, b, c) == RELATIVE_POSITION::LEFT;
}

bool jmk::leftOrBeyond(const Point2d& a, const Point2d& b, const Point2d& c)
{
	int position = orientation2d(a, b, c);
	return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}
